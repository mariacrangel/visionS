#include "vsmongo.h"

using namespace cv;
using namespace std;

VSMongo::VSMongo(string uri, string database_name){
    uri_ = uri;
    database_name_ = database_name;
    conn = mongocxx::client{mongocxx::uri{uri_}};
    database_ = conn[database_name_];
}

bool m_stringToBool(string s){
    if(s=="0")
        return false;
    return true;
}

int m_stringToInt(string s){
    return stoi(s);
}

vector<QString> stringListToVector(QStringList qss){
    vector<QString> res;
    for(int i=0;i<qss.size();i++)
        res.push_back(qss[i]);
    return res;
}

vector<string> splitSpaces(string s){
    vector<string> res;
    QStringList qss = QString::fromStdString(s).split(" ");
    for(int i=0;i<qss.size();i++)
        if(qss[i] != "")
            res.push_back(qss[i].toStdString());

    return res;
}

MGroup* VSMongo::loadGroup(string id,bool& ok){

    MGroup* mgp = new struct MGroup;
    mongocxx::cursor cursor = database_["GruposCamaras"].find(document{} << "_id" << bsoncxx::oid(id) << finalize);
    string estado = "0";

    string father_id;
    try{
        for (bsoncxx::document::view doc : cursor) {

            //cargar solo si tiene estado "1"
            bsoncxx::document::element stat_element{doc["Estado"]};
            estado = stat_element.get_utf8().value.to_string();

            if(estado == "1"){
                //get id
                bsoncxx::document::element id_element{doc["_id"]};
                mgp->id = id_element.get_oid().value.to_string();

                //get name
                bsoncxx::document::element name_element{doc["Nombre"]};
                mgp->name = name_element.get_utf8().value.to_string();

                //get type
                bsoncxx::document::element type_element{doc["Tipo"]};
                mgp->type = stoi(type_element.get_utf8().value.to_string());

                //get father name by id
                bsoncxx::document::element father_element{doc["Padre"]};
                father_id = father_element.get_oid().value.to_string();
                mgp->father = readField("GruposCamaras",father_id,"Nombre",ok).value;

                if(!ok) return NULL;
            }
        }

        ok = true;
        if(mgp->name!="Grupos"&&estado =="1")
            return mgp;
        else
            return NULL;

    }catch(const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }

    // no deberia llegar aca
    return NULL;
}

vector<MGroup*> VSMongo::getAllGroups(bool& ok){

    vector<MGroup*> res;
    vector<string> ids = getAllId("GruposCamaras",ok);
    if(!ok) return res;

    //for each group
    for(uint i=0;i<ids.size();i++){

        MGroup* mgp = loadGroup(ids[i],ok);
        if(!ok) return res;
        if(mgp != NULL)
            res.push_back(mgp);

    }
    return res;

}

vector<pair<string,int> > VSMongo::getAddonAlertTypes(string addon_name,bool&ok){

    vector<pair<string,int> > res;

    try{
        mongocxx::cursor cursor = database_["Sistema"].find({});
        for(bsoncxx::document::view doc : cursor){
            Json::Value root;
            Json::Reader reader;
            reader.parse(bsoncxx::to_json(doc), root);
            const Json::Value productos = root["Productos"];

            for(uint i = 0; i<productos.size();i++)
            {
                string producto = productos[i]["Producto"].asString();
                if(producto == addon_name){
                    const Json::Value alertas = productos[i]["Alertas"];
                    for(uint j =0; j < alertas.size(); j++){


                        int alert_id = stoi(alertas[j]["IDalerta"].asString());
                        string alert_name = alertas[j]["Alerta"].asString();
                        pair<string,int> alertinfo;
                        alertinfo.first = alert_name;
                        alertinfo.second = alert_id;
                        res.push_back(alertinfo);

                    }
                }
            }
            ok = true;
            return res;
        }
        ok = false;
        return res;

    } catch (const mqtt::exception &exc) {
            string error =" error: ";
            log( (string)exc.what() + error + (string)exc.get_message());
            ok = false;
    }

    return res;
}

string VSMongo::getAlertActionPlan(int addon_index,int alert_index,bool& ok){

    try{
        mongocxx::cursor cursor = database_["Sistema"].find({});


        for(bsoncxx::document::view doc : cursor){
            Json::Value root;
            Json::Reader reader;
            reader.parse(bsoncxx::to_json(doc), root);
            const Json::Value productos = root["Productos"];

            for(uint i = 0; i<productos.size();i++)
            {
                string producto = productos[i]["IDproducto"].asString();
                if(stoi(producto) == addon_index){
                    const Json::Value alertas = productos[i]["Alertas"];
                    for(uint j =0; j < alertas.size(); j++){
                        string alerta = alertas[j]["IDalerta"].asString();
                        if(stoi(alerta) == alert_index){
                            ok = true;
                            return alertas[j]["PlanDeAccion"].asString();
                        }
                    }
                }
            }
        }
        ok = false;
        return "";

    } catch (const mqtt::exception &exc) {
            string error =" error: ";
            log( (string)exc.what() + error + (string)exc.get_message());
            ok = false;
    }

    return "";
}

void VSMongo::removeRestreamEntry(string id,bool &ok){

    updateField("Restreams",id,"Estado","0",ok);
    if(!ok) return;
    log("Se elimina un restream de la base de datos");

}

string VSMongo::addRestreamEntry(QString name,QString origen,QString destino,bool & ok){

    //TODO antes chequear si esta repetido el nombre?

    mongocxx::client conn{mongocxx::uri{"mongodb://" + mongo_addr + ":27017"}};
    auto collection = conn["vCenterWeb"];

    bsoncxx::document::value entry = document{}
        << "Nombre" << name.toStdString()
        << "Origen" << origen.toStdString()
        << "Destino" << destino.toStdString()
        << "Estado" << "1"
        << "Ancho" << "0"
        << "Alto" << "0"
        << finalize;
    try{
        collection["Restreams"].insert_one(std::move(entry));
        ok = true;
        log("Se agrega un restream nuevo a la base de datos");

        //ahora devolver el oid que se genero
        mongocxx::cursor cursor = database_["Restreams"].find(document{} << "Nombre" << name.toStdString() << finalize);
        for (bsoncxx::document::view doc : cursor) {
            bsoncxx::document::element id_elem{doc["_id"]};
            return id_elem.get_oid().value.to_string();
        }

    } catch (const mqtt::exception &exc) {
            string error =" error: ";
            log( (string)exc.what() + error + (string)exc.get_message());
            ok = false;
    }

    // no deberia llegar aca
    return "";
}

vector<MRestream*> VSMongo::getRestreams(bool& ok){

    vector<MRestream*> res;

    vector<string> ids = getAllId("Restreams",ok);
    if(!ok) return res;

    try{
        for(uint i=0;i<ids.size();i++){
            mongocxx::cursor cursor = database_["Restreams"].find(document{} << "_id" << bsoncxx::oid(ids[i]) << finalize);
            for (bsoncxx::document::view doc : cursor) {

                bsoncxx::document::element estado_field{doc["Estado"]};
                string estado = estado_field.get_utf8().value.to_string();

                if(estado == "1"){
                    MRestream* restream = new struct MRestream;

                    bsoncxx::document::element id_field{doc["_id"]};
                    restream->id = id_field.get_oid().value.to_string();

                    bsoncxx::document::element name_field{doc["Nombre"]};
                    restream->name = name_field.get_utf8().value.to_string();

                    bsoncxx::document::element or_field{doc["Origen"]};
                    restream->origen = or_field.get_utf8().value.to_string();

                    bsoncxx::document::element des_field{doc["Destino"]};
                    restream->destino = des_field.get_utf8().value.to_string();

                    res.push_back(restream);
                }
            }
        }
        ok = true;
    } catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }
    return res;
}

void VSMongo::saveGlobalConfigs(bool& ok){

    vector<string> ids = getAllId("Sistema",ok);
    if(!ok) return;

    updateField("Sistema",ids[0],"BloqueGrabacion",to_string(video_block_minutes),ok);
    if(!ok) return;

    updateField("Sistema",ids[0],"DirectorioVideos",save_folder.toStdString(),ok);
    if(!ok) return;

    if(!write_timestamp){
        updateField("Sistema",ids[0],"Timestamp","Inactivo",ok);
        if(!ok)return;
    }else{
        updateField("Sistema",ids[0],"Timestamp",timestamp_color.toStdString()+"-"+timestamp_size.toStdString(),ok);
        if(!ok)return;
    }

    if(!control_on){
        updateField("Sistema",ids[0],"ControlDeGuardia","0-0-0-0",ok);
    }else{
        updateField("Sistema",ids[0],"ControlDeGuardia","1-"+to_string(control_from)+"-"+to_string(control_to)+"-"+to_string(control_tolerance),ok);
    }


    log("Se actualizan las configuraciones globales en la base de datos");
}

void VSMongo::addInactivityEntry(bool& ok){

    mongocxx::client conn{mongocxx::uri{"mongodb://" + mongo_addr + ":27017"}};
    auto collection = conn["vCenterWeb"];

    bsoncxx::document::value entry = document{}
        << "Usuario" << userinfo.username
        << "FechaHora"<< bsoncxx::types::b_date{std::chrono::milliseconds{QDateTime::currentMSecsSinceEpoch()}}
        << finalize;
    try{
        collection["Inactividades"].insert_one(std::move(entry));
        ok = true;
        log("Se registra que el operario esta inactivo");

    } catch (const mqtt::exception &exc) {
            string error =" error: ";
            log( (string)exc.what() + error + (string)exc.get_message());
            ok = false;
    }
}

void VSMongo::addRestEntry(qint64 from, qint64 to,bool& ok){

    mongocxx::client conn{mongocxx::uri{"mongodb://" + mongo_addr + ":27017"}};
    auto collection = conn["vCenterWeb"];

    bsoncxx::document::value entry = document{}
        << "Usuario" << userinfo.username
        << "FechaHoraDesde"<< bsoncxx::types::b_date{std::chrono::milliseconds{from}}
        << "FechaHoraHasta"<< bsoncxx::types::b_date{std::chrono::milliseconds{to}}
        << finalize;
    try{
        collection["Descansos"].insert_one(std::move(entry));
        ok = true;
        log("Se registra el descanso realizado por el operario");

    } catch (const mqtt::exception &exc) {
            string error =" error: ";
            log( (string)exc.what() + error + (string)exc.get_message());
            ok = false;
    }
}

void VSMongo::loadGlobalConfigs(bool& ok){

    try{
        vector<string> ids = getAllId("Sistema",ok);
        if(!ok) return;

        mongocxx::cursor cursor = database_["Sistema"].find(document{} << "_id" << bsoncxx::oid(ids[0]) << finalize);

        for (bsoncxx::document::view doc : cursor) {

            //cargar tamano de bloque de grabacion
            bsoncxx::document::element bloquegrabacion{doc["BloqueGrabacion"]};
            string bloque_s =bloquegrabacion.get_utf8().value.to_string();
            video_block_minutes = stoi(bloque_s);

            //cargar directorio de videos
            bsoncxx::document::element directoriovideos{doc["DirectorioVideos"]};
            save_folder = QString::fromStdString(directoriovideos.get_utf8().value.to_string());

            //cargar timestamp
            bsoncxx::document::element timestamp{doc["Timestamp"]};
            string timestamp_s = timestamp.get_utf8().value.to_string();
            if(timestamp_s == "Inactivo"){
                write_timestamp = false;
            }else{
                write_timestamp = true;
                timestamp_color = QString::fromStdString(timestamp_s).split("-")[0];
                timestamp_size = QString::fromStdString(timestamp_s).split("-")[1];
            }

            // cargar control de guardia
            bsoncxx::document::element control_guard{doc["ControlDeGuardia"]};
            string control_guard_s = control_guard.get_utf8().value.to_string();
            QStringList control_guard_ss = QString::fromStdString(control_guard_s).split("-");
            if(control_guard_ss.size()>3 && control_guard_ss[0].toInt() == 1){
                control_on = true;
                control_from = control_guard_ss[1].toInt();
                control_to = control_guard_ss[2].toInt();
                control_tolerance = control_guard_ss[3].toInt();

            }else{
                control_on = false;
            }




            return;

        }
        ok = true;

    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }
}

string m_boolToStr(bool b){
    if(b)
        return "1";
    return "0";
}

using namespace bsoncxx::builder::basic;

void VSMongo::updateGroup(MGroup mgroup,bool& ok){
    updateField("GruposCamaras",mgroup.id,"Nombre",mgroup.name,ok);
    if(!ok) return;

    updateField("GruposCamaras",mgroup.id,"Tipo",to_string(mgroup.type),ok);
    if(!ok) return;

    log("Se actualiza un grupo en la base de datos");
}

void VSMongo::removeGroupEntry(string id,bool& ok){
    updateField("GruposCamaras",id,"Estado","0",ok);
    if(!ok)return;
    log("Se elimina un grupo de la base de datos");
}


void VSMongo::removeDhDeviceEntry(string id,bool& ok){

    updateField("DispositivosDahua",id,"Estado","0",ok);
    if(!ok) return;
    log("Se elimina un dispositivo Dahua de la base de datos");

}

void VSMongo::removeCameraEntry(string id,bool& ok){
    updateField("Camaras",id,"Estado","0",ok);
    if(!ok) return;
    log("Se elimina una camara de la base de datos");
}

string VSMongo::addGroupEntry(MGroup mgroup,bool& ok){

    try{
        mongocxx::client conn{mongocxx::uri{"mongodb://" + mongo_addr + ":27017"}};
        auto collection = conn["vCenterWeb"];

        string nombre = mgroup.name;
        string tipo = to_string(mgroup.type);
        string id_padre = mgroup.father;

        bsoncxx::document::value entry = document{}
            << "Nombre" << nombre
            << "Tipo" << tipo
            << "Padre" << bsoncxx::oid(id_padre)
            << "Estado" << "1"
            << finalize;

        collection["GruposCamaras"].insert_one(std::move(entry));
        ok = true;
        log("Se agrega un grupo nuevo a la base de datos");

        //ahora devolver el oid que se genero
        mongocxx::cursor cursor = database_["GruposCamaras"].find(document{} << "Nombre" << nombre << finalize);
        for (bsoncxx::document::view doc : cursor) {
            bsoncxx::document::element id_elem{doc["_id"]};
            return id_elem.get_oid().value.to_string();
        }

    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }

    // no deberia llegar aca
    return "";
}

void VSMongo::updateCameraEntry(MCamera mcam,bool& ok){

    string id = mcam.id;
    updateField("Camaras",id,"Camara",mcam.name,ok);
    if(!ok) return;

    // general //
    string camara = mcam.name;
    string rotacion = to_string(mcam.transform_config.right_rotate_count*90);
    string mirror = m_boolToStr(mcam.transform_config.mirror);
    string rotaciones = to_string(mcam.transform_config.right_rotate_count);

    // record //
    string grabacion = "Inactivo";
    if(mcam.record_config.active)
        grabacion = "Activo";

    string fps = "Originales";
    if(mcam.record_config.change_out_fps)
        fps = "Disminuidos";

    string detectarmovimiento = "Inactivo";
    if(mcam.record_config.detect_movement)
        detectarmovimiento = "Activo";

    string mascaramovimiento = mcam.record_config.mask;
    string sensitivity = to_string(mcam.record_config.sensitivity);
    string history = to_string(mcam.record_config.history);
    string threshold = to_string(mcam.record_config.threshold);

    string ciclograbacion = "Inactivo";
    if(mcam.record_config.use_loop)
        ciclograbacion = to_string(mcam.record_config.loop_gigas);

    string scheduler = "Inactivo";
    if(mcam.record_config.use_scheduler)
        scheduler = mcam.record_config.scheduler;

    // alertas //
    string alerta = "Inactivo";
    if(mcam.alerts_config.active)
        alerta = "Activo";

    string idalerta = QString(mcam.alerts_config.addon+"-"+mcam.alerts_config.ip+"-"+mcam.alerts_config.instance).toStdString();

    string filtro_alerta = "";
    for(uint i=0;i<mcam.alerts_config.filter.size();i++)
        filtro_alerta += to_string(mcam.alerts_config.filter[i])+"-";

    string emails;
    for(uint i=0;i<mcam.alerts_config.smtp_receivers.size();i++)
        emails += mcam.alerts_config.smtp_receivers[i].toStdString()+" ";

    string usuariostelegram;
    for(uint i=0;i<mcam.alerts_config.tg_receivers.size();i++)
        usuariostelegram += mcam.alerts_config.tg_receivers[i].toStdString()+" ";

    // substream //
    string substreamrect = to_string(mcam.substream_config.cut_rect.x) + "-"+to_string(mcam.substream_config.cut_rect.y) + "-"+to_string(mcam.substream_config.cut_rect.width)+"-"+to_string(mcam.substream_config.cut_rect.height);

    // onvif //
    string onvif = "Inactivo";
    if(mcam.onvif_config.active)
        onvif = "Activo";

    string iponvif = mcam.onvif_config.ip;
    string puertoonvif = to_string(mcam.onvif_config.port);
    string usuarioonvif = mcam.onvif_config.user;
    string passwordonvif = mcam.onvif_config.password;
    string velocidadonvif = to_string(mcam.onvif_config.velocity);
    string timeoutonvif = to_string(mcam.onvif_config.timeout);
    string touronvif = "";
    for(uint i=0;i< mcam.onvif_config.tour.size();i++)
        touronvif += mcam.onvif_config.tour[i]+" ";
    string tourtimeonvif = to_string(mcam.onvif_config.it_time);


    updateField("Camaras",id,"Camara",camara,ok);
    if(!ok) return;
    updateField("Camaras",id,"Rotacion",rotacion,ok);
    if(!ok) return;
    updateField("Camaras",id,"Mirror",mirror,ok);
    if(!ok) return;
    updateField("Camaras",id,"Rotaciones",rotaciones,ok);
    if(!ok) return;
    updateField("Camaras",id,"Grabacion",grabacion,ok);
    if(!ok) return;

    if(grabacion == "Activo"){
        updateField("Camaras",id,"FPS",fps,ok);
        if(!ok) return;
        updateField("Camaras",id,"DetectarMovimiento",detectarmovimiento,ok);
        if(!ok) return;

        if(detectarmovimiento == "Activo"){
            updateField("Camaras",id,"MascaraMovimiento",mascaramovimiento,ok);
            if(!ok) return;
            updateField("Camaras",id,"Sensitivity",sensitivity,ok);
            if(!ok) return;
            updateField("Camaras",id,"History",history,ok);
            if(!ok) return;
            updateField("Camaras",id,"Threshold",threshold,ok);
            if(!ok) return;
        }
        updateField("Camaras",id,"CicloGrabacion",ciclograbacion,ok);
        if(!ok) return;
        updateField("Camaras",id,"Scheduler",scheduler,ok);
        if(!ok) return;
    }
    updateField("Camaras",id,"Alerta",alerta,ok);
    if(!ok) return;
    if(alerta == "Activo"){
        updateField("Camaras",id,"IDAlerta",idalerta,ok);
        if(!ok) return;
        updateField("Camaras",id,"FiltroAlerta",filtro_alerta,ok);
        if(!ok) return;
        updateField("Camaras",id,"Emails",emails,ok);
        if(!ok) return;
        updateField("Camaras",id,"UsuariosTelegram",usuariostelegram,ok);
        if(!ok) return;
    }
    if(mcam.substream_config.is_substream){
        updateField("Camaras",id,"SubstreamRect",substreamrect,ok);
        if(!ok) return;
    }
    updateField("Camaras",id,"Onvif",onvif,ok);
    if(onvif == "Activo"){
        updateField("Camaras",id,"IPOnvif",iponvif,ok);
        if(!ok) return;
        updateField("Camaras",id,"PuertoOnvif",puertoonvif,ok);
        if(!ok) return;
        updateField("Camaras",id,"UsuarioOnvif",usuarioonvif,ok);
        if(!ok) return;
        updateField("Camaras",id,"PasswordOnvif",passwordonvif,ok);
        if(!ok) return;
        updateField("Camaras",id,"VelocidadOnvif",velocidadonvif,ok);
        if(!ok) return;
        updateField("Camaras",id,"TimeoutOnvif",timeoutonvif,ok);
        if(!ok) return;
        updateField("Camaras",id,"TourOnvif",touronvif,ok);
        if(!ok) return;
        updateField("Camaras",id,"TourTimeOnvif",tourtimeonvif,ok);
        if(!ok) return;
    }
    log("Se actualiza una camara en la base de datos");

}

string VSMongo::addDhDeviceEntry(MDhDevice mdh,bool& ok){
    mongocxx::client conn{mongocxx::uri{"mongodb://" + mongo_addr + ":27017"}};
    auto collection = conn["vCenterWeb"];

    try{
        bsoncxx::document::value entry = document{}
            << "Estado" << "1"
            << "Nombre" << mdh.name
            << "CantCanales"<< to_string(mdh.channels_count)
            << "Grupo" << bsoncxx::oid(mdh.group_id)
            << "IP" << mdh.ip
            << "Puerto" << to_string(mdh.port)
            << "Usuario" << mdh.user
            << "Contraseña" << mdh.pass
            << "Camaras" << open_array << close_array
            << finalize;

        collection["DispositivosDahua"].insert_one(std::move(entry));

        for(int i =0;i<mdh.channels_count;i++){
            if(mdh.cameras[i] != ""){
                    bsoncxx::builder::stream::document filter_builder, update_builder;
                    filter_builder << "Nombre" << mdh.name;
                    update_builder << "$push" << open_document
                                    << "Id" << bsoncxx::oid(mdh.cameras[i])
                                    << "Canal" << to_string(i)
                                    << close_document << close_document;
                    collection["DispositivosDahua"].update_one(filter_builder.view(), update_builder.view());
            }
        }

        //ahora devolver el oid que se genero
        mongocxx::cursor cursor = database_["DispositivosDahua"].find(document{} << "Nombre" << mdh.name << "Estado" << "1" << finalize);
        for (bsoncxx::document::view doc : cursor) {
            bsoncxx::document::element id_elem{doc["_id"]};
            ok = true;
            log("Se agrega un dispositivo dahua nuevo a la base de datos");
            return id_elem.get_oid().value.to_string();
        }

    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
        return "";
    }

    return "";
}

string VSMongo::addCameraEntry(MCamera mcam,bool& ok){

    mongocxx::client conn{mongocxx::uri{"mongodb://" + mongo_addr + ":27017"}};
    auto collection = conn["vCenterWeb"];

    //general
    string camara = mcam.name;
    string estado = "1";
    string protocolo = "RTSP";
    string rotacion = to_string(mcam.transform_config.right_rotate_count*90);
    string direccion = mcam.addr;
    string grupo_id = mcam.group_id;

    string mirror = m_boolToStr(mcam.transform_config.mirror);
    string rotaciones = to_string(mcam.transform_config.right_rotate_count);

    //record
    string grabacion;
    if(mcam.record_config.active)
        grabacion = "Activo";
    else
        grabacion = "Inactivo";
    string fps;
    if(mcam.record_config.change_out_fps)
        fps = "Disminuidos";
    else
        fps = "Originales";

    string detectarmovimiento;
    if(mcam.record_config.detect_movement)
        detectarmovimiento = "Activo";
    else
        detectarmovimiento = "Inactivo";

    string mascaramovimiento = mcam.record_config.mask;
    string sensitivity = to_string(mcam.record_config.sensitivity);
    string history = to_string(mcam.record_config.history);
    string threshold = to_string(mcam.record_config.threshold);
    string ciclograbacion;

    if(mcam.record_config.use_loop)
        ciclograbacion = to_string(mcam.record_config.loop_gigas);
    else
        ciclograbacion = "Inactivo";

    string scheduler;
    if(mcam.record_config.use_scheduler)
        scheduler = mcam.record_config.scheduler;
    else
        scheduler = "Inactivo";


    //alertas
    string alerta;
    if(mcam.alerts_config.active)
        alerta = "Activo";
    else
        alerta = "Inactivo";
    string idalerta = QString(mcam.alerts_config.addon+"-"+mcam.alerts_config.ip+"-"+mcam.alerts_config.instance).toStdString();

    string filtro_alerta = "";
    for(uint i=0;i<mcam.alerts_config.filter.size();i++)
        filtro_alerta += to_string(mcam.alerts_config.filter[i])+"-";

    string emails;
    for(uint i=0;i<mcam.alerts_config.smtp_receivers.size();i++)
        emails += mcam.alerts_config.smtp_receivers[i].toStdString()+" ";

    string usuariostelegram;
    for(uint i=0;i<mcam.alerts_config.tg_receivers.size();i++)
        usuariostelegram += mcam.alerts_config.tg_receivers[i].toStdString()+" ";

    // substream
    string substream;
    string substream_father_id;
    if(!mcam.substream_config.is_substream){
        substream = "Inactivo";
        vector<string> sys_ids = getAllId("Sistema",ok);
        if(!ok) return "";

        substream_father_id = sys_ids[0];
    }else{
        substream = "Activo";
        substream_father_id = mcam.substream_config.father_camera->unique_id_; // id del padre
    }

    string substreamrect = to_string(mcam.substream_config.cut_rect.x) + "-" +to_string(mcam.substream_config.cut_rect.y) + "-"+to_string(mcam.substream_config.cut_rect.width)+"-"+to_string(mcam.substream_config.cut_rect.height);

    // onvif
    string onvif;
    if(mcam.onvif_config.active)
        onvif = "Activo";
    else
        onvif = "Inactivo";

    string iponvif = mcam.onvif_config.ip;
    string puertoonvif = to_string(mcam.onvif_config.port);
    string usuarioonvif = mcam.onvif_config.user;
    string passwordonvif = mcam.onvif_config.password;
    string velocidadonvif = to_string(mcam.onvif_config.velocity);
    string timeoutonvif = to_string(mcam.onvif_config.timeout);
    string touronvif = "";

    for(uint i=0;i< mcam.onvif_config.tour.size();i++)
        touronvif += mcam.onvif_config.tour[i]+" ";

    string tourtimeonvif = to_string(mcam.onvif_config.it_time);

    try{
        bsoncxx::document::value entry = document{}
            << "Camara" << camara
            << "Estado" << estado
            << "Protocolo" << protocolo
            << "Rotacion"<< rotacion
            << "Direccion" << direccion
            << "Grupo" << bsoncxx::oid(grupo_id)
            << "Mirror" << mirror
            << "Rotaciones" << rotaciones
            << "Grabacion" << grabacion
            << "FPS" << fps
            << "DetectarMovimiento" << detectarmovimiento
            << "MascaraMovimiento" << mascaramovimiento
            << "Sensitivity" << sensitivity
            << "History" << history
            << "Threshold" << threshold
            << "CicloGrabacion" << ciclograbacion
            << "Scheduler" << scheduler
            << "Alerta" << alerta
            << "IDAlerta" << idalerta
            << "FiltroAlerta" << filtro_alerta
            << "Emails" << emails
            << "UsuariosTelegram" << usuariostelegram
            << "Substream" << substream
            << "SubstreamPadre" << bsoncxx::oid(substream_father_id)
            << "SubstreamRect" << substreamrect
            << "Onvif" << onvif
            << "IPOnvif" << iponvif
            << "PuertoOnvif" << puertoonvif
            << "UsuarioOnvif" << usuarioonvif
            << "PasswordOnvif" << passwordonvif
            << "VelocidadOnvif" << velocidadonvif
            << "TimeoutOnvif" << timeoutonvif
            << "TourOnvif" << touronvif
            << "TourTimeOnvif" << tourtimeonvif
            << finalize;

        collection["Camaras"].insert_one(std::move(entry));

        //ahora devolver el oid que se genero
        mongocxx::cursor cursor = database_["Camaras"].find(document{} << "Camara" << camara << "Estado" << "1" << finalize);
        for (bsoncxx::document::view doc : cursor) {
            bsoncxx::document::element id_elem{doc["_id"]};
            ok = true;
            log("Se agrega una camara nueva a la base de datos");
            return id_elem.get_oid().value.to_string();
        }


    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
        return "";
    }

    // no deberia llegar aca
    return "";
}

MDhDevice VSMongo::loadDhDevice(string id,bool& ok){
    MDhDevice mdh;

    try{
        mongocxx::cursor cursor = database_["DispositivosDahua"].find(document{} << "_id" << bsoncxx::oid(id) << finalize);

        for (bsoncxx::document::view doc : cursor) {

            bsoncxx::document::element stat_element{doc["Estado"]};
            if(stat_element.get_utf8().value.to_string()=="1"){

                // id
                bsoncxx::document::element id_elem{doc["_id"]};
                mdh.id = id_elem.get_oid().value.to_string();

                // estado
                mdh.active = true;

                // nombre
                bsoncxx::document::element name_element{doc["Nombre"]};
                mdh.name = name_element.get_utf8().value.to_string();

                // canales
                bsoncxx::document::element ch_element{doc["CantCanales"]};
                mdh.channels_count = m_stringToInt(ch_element.get_utf8().value.to_string());

                // grupo
                bsoncxx::document::element groupid_elem{doc["Grupo"]};
                mdh.group_id = groupid_elem.get_oid().value.to_string();

                // IP
                bsoncxx::document::element ip_element{doc["IP"]};
                mdh.ip = ip_element.get_utf8().value.to_string();

                // puerto
                bsoncxx::document::element port_element{doc["Puerto"]};
                mdh.port = m_stringToInt(port_element.get_utf8().value.to_string());

                // usuario
                bsoncxx::document::element user_element{doc["Usuario"]};
                mdh.user = user_element.get_utf8().value.to_string();

                // password
                bsoncxx::document::element pass_element{doc["Contraseña"]};
                mdh.pass = pass_element.get_utf8().value.to_string();

            }else{
                mdh.active=false;
            }

        }

        ok = true;
        return mdh;

    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }

    // no deberia llegar aca
    return mdh;
}

MCamera VSMongo::loadCamera(string id,bool& ok){
    MCamera mcam;
    try{
        mongocxx::cursor cursor = database_["Camaras"].find(document{} << "_id" << bsoncxx::oid(id) << finalize);

        for (bsoncxx::document::view doc : cursor) {

            bsoncxx::document::element stat_element{doc["Estado"]};

            //si la camara esta activa
            if(stat_element.get_utf8().value.to_string()=="1"){

                mcam.active = true;

                //id
                bsoncxx::document::element id_elem{doc["_id"]};
                mcam.id = id_elem.get_oid().value.to_string();

                //general
                bsoncxx::document::element name_element{doc["Camara"]};
                mcam.name = name_element.get_utf8().value.to_string();
                bsoncxx::document::element addr_element{doc["Direccion"]};
                mcam.addr = addr_element.get_utf8().value.to_string();

                //grupo
                bsoncxx::document::element group_element{doc["Grupo"]};
                string group_id = group_element.get_oid().value.to_string();
                mcam.group_id = group_id;

                //transform
                CameraTransformConfig t_config;
                bsoncxx::document::element mirror_element{doc["Mirror"]};
                t_config.mirror = m_stringToBool(mirror_element.get_utf8().value.to_string());
                bsoncxx::document::element rotate_element{doc["Rotaciones"]};
                t_config.right_rotate_count = m_stringToInt(rotate_element.get_utf8().value.to_string());
                mcam.transform_config = t_config;

                //record
                CameraRecordConfig r_config;
                bsoncxx::document::element record_element{doc["Grabacion"]};
                string record_s = record_element.get_utf8().value.to_string();

                if(record_s == "Inactivo"){
                    r_config.active = false;
                }else{
                    r_config.active = true;

                    //fps
                    bsoncxx::document::element fps_element{doc["FPS"]};
                    string fps_s = fps_element.get_utf8().value.to_string();
                    if(fps_s == "Disminuidos")
                        r_config.change_out_fps = true;
                    else
                        r_config.change_out_fps = false;

                    //detect movement
                    bsoncxx::document::element detectmov_element{doc["DetectarMovimiento"]};
                    string detmov_s = detectmov_element.get_utf8().value.to_string();


                    if(detmov_s == "Inactivo"){
                        r_config.detect_movement = false;
                    }else{
                        r_config.detect_movement = true;

                        //mask
                        bsoncxx::document::element mask_element{doc["MascaraMovimiento"]};
                        string mask_s = mask_element.get_utf8().value.to_string();

                        if(mask_s == "Inactivo"){
                            r_config.use_mask = false;

                        }else{
                            r_config.use_mask = true;
                            r_config.mask = mask_s;

                            //sensitivity
                            bsoncxx::document::element sens_element{doc["Sensitivity"]};
                            r_config.sensitivity = m_stringToInt(sens_element.get_utf8().value.to_string());

                            //history
                            bsoncxx::document::element his_element{doc["History"]};
                            r_config.history = m_stringToInt(his_element.get_utf8().value.to_string());

                            //threshold
                            bsoncxx::document::element thres_element{doc["Threshold"]};
                            r_config.threshold = m_stringToInt(thres_element.get_utf8().value.to_string());
                        }
                    }

                    //loop
                    bsoncxx::document::element loop_element{doc["CicloGrabacion"]};
                    string loop_s = loop_element.get_utf8().value.to_string();
                    if(loop_s == "Inactivo"){
                        r_config.use_loop = false;
                    }else{
                        r_config.use_loop = true;
                        r_config.loop_gigas = stoi(loop_s);
                    }

                    //scheduler
                    bsoncxx::document::element sched_element{doc["Scheduler"]};
                    string sched_s = sched_element.get_utf8().value.to_string();
                    if(sched_s == "Inactivo"){
                        r_config.use_scheduler = false;
                    }else{
                        r_config.use_scheduler = true;
                        r_config.scheduler = sched_s;
                    }

                }
                mcam.record_config = r_config;


                //alert
                CameraAlertsConfig a_config;
                bsoncxx::document::element alert_element{doc["Alerta"]};
                string alert_s = alert_element.get_utf8().value.to_string();
                if(alert_s == "Activo"){
                    a_config.active = true;

                    //alert id
                    bsoncxx::document::element alertid_element{doc["IDAlerta"]};
                    string id_s = alertid_element.get_utf8().value.to_string();
                    a_config.addon = QString::fromStdString(id_s).split("-")[0];
                    a_config.ip = QString::fromStdString(id_s).split("-")[1];
                    a_config.instance = QString::fromStdString(id_s).split("-")[2];

                    //filter alert
                    bsoncxx::document::element alertfilter_element{doc["FiltroAlerta"]};
                    string alert_f = alertfilter_element.get_utf8().value.to_string();
                    vector<int> alert_f_v;
                    QStringList al_qss = QString::fromStdString(alert_f).split("-");
                    for(int i=0;i<al_qss.size();i++)
                        if(al_qss[i] != "")
                            alert_f_v.push_back(al_qss[i].toInt());
                    a_config.filter = alert_f_v;

                    //smtp
                    bsoncxx::document::element smtp_element{doc["Emails"]};
                    string smtp_s = smtp_element.get_utf8().value.to_string();
                    a_config.smtp_receivers = stringListToVector(QString::fromStdString(smtp_s).split(" "));

                    //telegram
                    bsoncxx::document::element tg_element{doc["UsuariosTelegram"]};
                    string tg_s = tg_element.get_utf8().value.to_string();
                    a_config.tg_receivers = stringListToVector(QString::fromStdString(tg_s).split(" "));



                }else{
                    a_config.active = false;
                }

                mcam.alerts_config = a_config;

                //substream
                CameraSubstreamConfig s_config;
                bsoncxx::document::element subs_element{doc["Substream"]};
                string subs_s = subs_element.get_utf8().value.to_string();

                if(subs_s == "Inactivo"){
                    s_config.is_substream = false;
                }else{
                    s_config.is_substream = true;

                    bsoncxx::document::element subsf_element{doc["SubstreamPadre"]};
                    mcam.substream_father_id = subsf_element.get_oid().value.to_string();

                    bsoncxx::document::element srect_element{doc["SubstreamRect"]};
                    string srect_s = srect_element.get_utf8().value.to_string();
                    s_config.cut_rect = Rect(QString::fromStdString(srect_s).split("-")[0].toInt(),
                            QString::fromStdString(srect_s).split("-")[1].toInt(),
                            QString::fromStdString(srect_s).split("-")[2].toInt(),
                            QString::fromStdString(srect_s).split("-")[3].toInt());
                }
                mcam.substream_config = s_config;

                //onvif
                CameraOnvifConfig o_config;
                bsoncxx::document::element onvif_element{doc["Onvif"]};
                string onvif_s = onvif_element.get_utf8().value.to_string();
                if(onvif_s == "Inactivo"){

                    o_config.active = false;
                }else{
                    o_config.active = true;
                    bsoncxx::document::element ip_onvif_element{doc["IPOnvif"]};
                    o_config.ip = ip_onvif_element.get_utf8().value.to_string();
                    bsoncxx::document::element port_onvif_element{doc["PuertoOnvif"]};
                    o_config.port = stoi(port_onvif_element.get_utf8().value.to_string());
                    bsoncxx::document::element user_onvif_element{doc["UsuarioOnvif"]};
                    o_config.user = user_onvif_element.get_utf8().value.to_string();
                    bsoncxx::document::element pass_onvif_element{doc["PasswordOnvif"]};
                    o_config.password = pass_onvif_element.get_utf8().value.to_string();
                    bsoncxx::document::element vel_onvif_element{doc["VelocidadOnvif"]};
                    o_config.velocity = stod(vel_onvif_element.get_utf8().value.to_string());
                    bsoncxx::document::element timeout_onvif_element{doc["TimeoutOnvif"]};
                    o_config.timeout = stod(timeout_onvif_element.get_utf8().value.to_string());

                    bsoncxx::document::element tour_onvif_element{doc["TourOnvif"]};
                    string tour_s = tour_onvif_element.get_utf8().value.to_string();
                    if(tour_s == "Inactivo"){
                        vector<string> voidvec;
                        o_config.tour = voidvec;
                    }else{

                        o_config.tour = splitSpaces(tour_s);

                        bsoncxx::document::element tourtime_onvif_element{doc["TourTimeOnvif"]};
                        o_config.it_time = stoi(tourtime_onvif_element.get_utf8().value.to_string());
                    }
                }

                mcam.onvif_config = o_config;
            }else{
                mcam.active = false;
            }
        }

        ok = true;
        return mcam;

    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }

    // no deberia llegar aca
    return mcam;
}

int VSMongo::getActiveCamerasCount(bool& ok){
    try{
        int active_cameras = 0;
        vector<string> ids = getAllId("Camaras",ok);
        if(!ok) return 9999;

        for(uint i=0;i<ids.size();i++){
            mongocxx::cursor cursor = database_["Camaras"].find(document{} << "_id" << bsoncxx::oid(ids[i]) << finalize);

            for (bsoncxx::document::view doc : cursor) {

                bsoncxx::document::element stat_element{doc["Estado"]};

                //si la camara esta activa
                if(stat_element.get_utf8().value.to_string()=="1"){
                    active_cameras++;
                    break;
                }
            }
        }
        ok = true;
        return active_cameras;
    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
        return 9999;
    }
}

vector<MCamera> VSMongo::getAllCameras(bool& ok){

    vector<MCamera> res;
    vector<string> ids = getAllId("Camaras",ok);
    if(!ok) return res;

    //para cada entrada en la coleccion de camaras
    for(uint i=0;i<ids.size();i++){
        MCamera mcam = loadCamera(ids[i],ok);
        if(!ok) return res;

        if(mcam.active)
            res.push_back(mcam);
    }

    return res;
}

vector<MDhDevice> VSMongo::getAllDhDevices(bool& ok){

    vector<MDhDevice> res;
    vector<string> ids = getAllId("DispositivosDahua",ok);
    if(!ok)return res;

    for(uint i=0;i<ids.size();i++){
        MDhDevice mdh = loadDhDevice(ids[i],ok);
        if(!ok) return res;

        if(mdh.active)
            res.push_back(mdh);
    }

    return res;

}

Field VSMongo::readField(string collection ,string id,string field_key,bool& ok){
    Field res;

    try{
        mongocxx::cursor cursor = database_[collection].find(document{} << "_id" << bsoncxx::oid(id) << finalize);
        res.key = field_key;

        for (bsoncxx::document::view doc : cursor) {

            bsoncxx::document::element element{doc[field_key]};
            res.type = element.type();

            if(res.type == bsoncxx::type::k_oid)
                res.value = element.get_oid().value.to_string();
            else
                res.value = element.get_utf8().value.to_string();

            return res;
        }
        ok = true;
    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }

    // nodeberia llegar aca
    return res;
}

vector<string> VSMongo::getAllId(string collection,bool& ok){
    vector<string> res;
    try{
        mongocxx::cursor cursor = database_[collection].find({});

        for (bsoncxx::document::view doc : cursor) {
            bsoncxx::to_json(doc);
            bsoncxx::document::element element{doc["_id"]};
            res.push_back(element.get_oid().value.to_string());
        }
        ok = true;
    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }
    return res;
}

void VSMongo::updateField(string collection,string oid, string field,string newvalue,bool& ok){

    try{
        bsoncxx::builder::stream::document filter_builder1, update_builder1;

        filter_builder1 << "_id" << bsoncxx::oid(oid);
        update_builder1 << "$set" << open_document
                        << field << newvalue
                        << close_document;

        database_[collection].update_one(filter_builder1.view(), update_builder1.view());
        ok = true;
    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }
}

string VSMongo::getId(string collection, string field, string value,bool& ok){
    try{
        mongocxx::cursor cursor = database_[collection].find(document{} << field << value << finalize);
        for (bsoncxx::document::view doc : cursor) {

            bsoncxx::document::element element{doc["_id"]};
            ok = true;
            return element.get_oid().value.to_string();
        }
        ok = true;
        return "";
    }catch (const mqtt::exception &exc) {
        string error =" error: ";
        log( (string)exc.what() + error + (string)exc.get_message());
        ok = false;
    }

    // no deberia llegar aca
    return "";
}

vector<MEmap*> parseEmaps(string emaps_s){

    vector<MEmap*> res;
    QStringList qsl = QString::fromStdString(emaps_s).split(";");

    int index = 0;

    if(qsl.size()>0){
        int emaps_count = qsl[index].toInt();
        index++;

        for(int i=0;i<emaps_count;i++){
            MEmap* emap = new struct MEmap;

            emap->name = qsl[index].toStdString();
            index++;

            if(qsl[index]=="0")
                emap->independent = false;
            else
                emap->independent = true;

            index++;
            emap->image = qsl[index].toStdString();
            index++;

            vector<string>cameras;
            vector<string>positions;

            int cameras_count = qsl[index].toInt();
            index++;
            for(int j =0;j<cameras_count;j++){
                cameras.push_back(qsl[index].toStdString());
                positions.push_back(qsl[index+1].toStdString());
                index+=2;
            }
            emap->cameras_id = cameras;
            emap->cameras_position = positions;
            res.push_back(emap);
        }
    }

    return res;
}

vector<MGrid*> parseGrids(string grids_s){

    vector<MGrid*> res;
    QStringList qsl = QString::fromStdString(grids_s).split(";");

    if(qsl.size()>0){
        int grids_count = qsl[0].toInt();

        for(int i=0;i<grids_count;i++){
            MGrid* grid = new struct MGrid;

            grid->name = qsl[i*185+1].toStdString();
            string is_indep_s = qsl[i*185+2].toStdString();
            if(is_indep_s == "0")
                grid->independent = false;
            else
                grid->independent = true;

            grid->type = qsl[i*185+3].toInt();

            vector<string>ids;
            for(uint j=0;j<182;j++)
                ids.push_back(qsl[i*185+4+j].toStdString());

            grid->cameras_id = ids;
            res.push_back(grid);

        }
    }
    return res;
}

bool VSMongo::logIn(string lowcase_user, string password,bool& ok){

    vector<string> user_ids = getAllId("Personas",ok);

    if(!ok)
        return false;

    for(uint i=0;i<user_ids.size();i++){

        Field f_u = readField("Personas",user_ids[i],"Usuario",ok);

        if(!ok) return false;

        if(f_u.value == lowcase_user){

            userinfo.id = user_ids[i];

            Field f_p = readField("Personas",user_ids[i],"PasswordCW",ok);
            if(!ok) return false;

            if(XorCipher::encrypt(f_p.value) == password){

                userinfo.username = lowcase_user;
                userinfo.password = password;

                //buscar el rol..
                string rol_id = readField("Personas",user_ids[i],"Rol",ok).value;
                if(!ok) return false;

                string rol_name = readField("Roles",rol_id,"Rol",ok).value;
                if(!ok) return false;

                userinfo.rol = rol_name;

                //tab actual
                userinfo.tabactual = readField("Personas",user_ids[i],"TabActualVC",ok).value;
                if(!ok) return false;

                //grillas
                string grids_s = readField("Personas",user_ids[i],"GrillasVC",ok).value;
                if(!ok) return false;

                vector <MGrid*> grids_v = parseGrids(grids_s);
                userinfo.grids = grids_v;

                //emaps
                string emaps_s = readField("Personas",user_ids[i],"EmapsVC",ok).value;
                if(!ok) return false;

                vector <MEmap*> emaps_v = parseEmaps(emaps_s);
                userinfo.emaps = emaps_v;

                //playback
                string p_cameras = readField("Personas",user_ids[i],"PlaybackCamaras",ok).value;
                if(!ok) return false;
                vector<string> p_cameras_v;
                QStringList qss = QString::fromStdString(p_cameras).split(";");
                for(int i = 0 ; i < qss.size() ; i++){

                    //TODO chequear que la camara tenga estado 1
                    p_cameras_v.push_back(qss[i].toStdString());

                }

                userinfo.playback_cameras = p_cameras_v;

                string changesize = readField("Personas",user_ids[i],"PlaybackCambiarTamaño",ok).value;
                if(!ok) return false;
                userinfo.playback_changesize = (changesize == "1");

                string skipframes = readField("Personas",user_ids[i],"PlaybackSaltearFotogramas",ok).value;
                if(!ok) return false;
                userinfo.playback_skipframes = (skipframes == "1");

                userinfo.playback_secs = stoi(readField("Personas",user_ids[i],"PlaybackSegundos",ok).value);
                if(!ok) return false;

                //buscar los permisos
                try{
                    mongocxx::cursor cursor = database_["Roles"].find(document{} << finalize);
                    for (bsoncxx::document::view doc : cursor) {
                        bsoncxx::document::element element{doc["Rol"]};
                        if(element.get_utf8().value.to_string() == rol_name){
                            QString permisos_json = QString::fromStdString(bsoncxx::to_json(doc));
                            userinfo.advanced_camera_configs_access =  permisos_json.contains("\"Direccion\" : \"ConfiguracionAvanzadaCamara");
                            userinfo.basic_camera_configs_access =  permisos_json.contains("\"Direccion\" : \"ConfiguracionBasicaCamara");
                            userinfo.all_cameras_access = permisos_json.contains("\"Direccion\" : \"AccesoCamaras");
                            userinfo.global_configs_access = permisos_json.contains("\"Direccion\" : \"ConfiguracionGlobal");
                        }
                    }

                    userinfo.login = true;
                    ok = true;
                    return true;
                }catch (const mqtt::exception &exc) {
                    string error =" error: ";
                    log( (string)exc.what() + error + (string)exc.get_message());
                    ok = false;
                    return false;
                }

            }else{
                return false;
            }
        }
    }
    return false;
}

void VSMongo::updateUserInfoTabActual(bool& ok){

    // actualizar TabActualVC en mongo
    string user_id = getId("Personas","Usuario",userinfo.username,ok);
    if(!ok)
        return;
    updateField("Personas",user_id,"TabActualVC",userinfo.tabactual,ok);

}

void VSMongo::updateUserInfoPlaybackConfigs(bool &ok){
    string user_id = getId("Personas","Usuario",userinfo.username,ok);
    if(!ok)
        return;
    updateField("Personas",user_id,"PlaybackSegundos",to_string(userinfo.playback_secs),ok);
    updateField("Personas",user_id,"PlaybackCambiarTamaño", m_boolToStr(userinfo.playback_changesize),ok);
    updateField("Personas",user_id,"PlaybackSaltearFotogramas",m_boolToStr(userinfo.playback_skipframes),ok);
}

void VSMongo::updateUserInfoPlayBackCameras(bool &ok){

    string user_id = getId("Personas","Usuario",userinfo.username,ok);
    if(!ok)
        return;

    string playback_cameras_ids_list = "";
    for(uint i=0;i<userinfo.playback_cameras.size();i++){
        if(i!=0)
            playback_cameras_ids_list+=";";
        playback_cameras_ids_list += userinfo.playback_cameras[i];
    }

    updateField("Personas",user_id,"PlaybackCamaras",playback_cameras_ids_list,ok);

}

void VSMongo::updateUserInfoGrids(bool& ok){


    //actualizar GrillasVC en mongo
    string grillas_s = to_string(userinfo.grids.size())+";";
    for(uint i=0;i<userinfo.grids.size();i++){
        if(i!=0)
            grillas_s+=";";
        grillas_s += userinfo.grids[i]->name+";";
        if(userinfo.grids[i]->independent)
            grillas_s+= "1";
        else
            grillas_s+= "0";
        grillas_s += ";"+to_string(userinfo.grids[i]->type);

        for(uint c=0;c<userinfo.grids[i]->cameras_id.size();c++)
            grillas_s+=";"+userinfo.grids[i]->cameras_id[c];
    }
    string user_id = getId("Personas","Usuario",userinfo.username,ok);
    if(!ok)
        return;
    updateField("Personas",user_id,"GrillasVC",grillas_s,ok);

    log("Se actualizaron las grillas del usuario");

}

void VSMongo::updateUserInfoEmaps(bool& ok){

    //actualizar EmapsVC en mongo
    string emaps_s = to_string(userinfo.emaps.size())+";";

    for(uint i=0;i<userinfo.emaps.size();i++){
        if(i!=0)
            emaps_s+=";";

        emaps_s += userinfo.emaps[i]->name+";";
        if(userinfo.emaps[i]->independent)
            emaps_s+= "1";
        else
            emaps_s+= "0";
        emaps_s += ";"+userinfo.emaps[i]->image;
        emaps_s += ";"+to_string(userinfo.emaps[i]->cameras_id.size());

        for(uint c=0;c<userinfo.emaps[i]->cameras_id.size();c++){
            emaps_s+=";"+userinfo.emaps[i]->cameras_id[c];
            emaps_s+=";"+userinfo.emaps[i]->cameras_position[c];
        }
    }

    string user_id = getId("Personas","Usuario",userinfo.username,ok);
    if(!ok) return;
    updateField("Personas",user_id,"EmapsVC",emaps_s,ok);

    log("Se actualizaron los emaps del usuario");
}

