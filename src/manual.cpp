#include "manual.h"
#include "ui_manual.h"

using namespace std;

Manual::Manual(QWidget *parent) : QDialog(parent), ui(new Ui::Manual) {
    ui->setupUi(this);
    this->setStyleSheet(curr_style);
    log("Se abre ventana: Manual");
}

Manual::~Manual()      {
    delete ui;
}

void Manual::on_list_clicked(const QModelIndex &index ){
    QString text = index.data().toString();
    ui->title->setText(text);

    if (text == "Usuarios") {
        ui->page->setText(
                    "Al iniciar el VCenterViewer, debe ingresarse un usuario y contraseña válidos. \n"
                    "Los usuarios se crean únicamente por la interfaz web.\n"
                    "\n"
                    "Cada usuario tiene un conjunto de grupos de cámaras disponibles para visualizar, y tiene permisos distintos para cambiar las configuraciones globales.\n"
                    "Los permisos son:\n"
                    "- Cambiar configuraciones globales\n"
                    "- Configuraciones avanzadas de cámaras: comprende todas las configuraciones de las cámaras. Además, se permite crear nuevas cámaras y grupos.\n"
                    "- Configuraciones básicas de cámaras: comprende solo las configuraciones de visualización y de PTZ.\n"
                    "\n"
                    "Las grillas, ventanas y emaps que el usuario cree, son solo de ese usuario y se guardan en la base de datos inmediatamente cada vez que hay un cambio.\n"
                    "Esto es, cuando un usuario cierra sesión se guardan todas las visualizaciones, y cuando vuelve a iniciar sesión vuelve a ver las mismas grillas y emaps."

                    );
    }

    if(text == "Interfaz"){

        ui->page->setText(

                    "La interfaz del VCenterViewer esta compuesta por:\n"
                    "\n"
                    "- La barra de menú.\n"
                    ""
                    "- Una lista de grupos de cámaras en la parte izquierda, con la cual se puede agregar, quitar y modificar cámaras y grupos si se tienen los permisos. Tambien se permite arrastrar las cámaras a las grillas para visualizarlas.\n"
                    "- Un cuadro de pestañas en en centro, que agrupa las pestañas de grillas y emaps del usuario. Ver secciones Grillas y Emaps.\n"
                    "- Una barra de accesos rápidos, que contiene algunas funciones que estan disponibles tambien en la barra de menú. Ésta se puede esconder o mover a gusto.\n"
                    "- Una lista de alertas. Ver sección Alertas.\n"

                    );
    }

    if(text == "Grupos"){
        ui->page->setText("Los grupos son contenedores de cámaras, y de otros grupos. \n \n Se puede crear un sub-grupo de un grupo ya existente, haciendo clic derecho sobre el mismo. \n Cuando se crea un grupo, tiene un nombre y un ícono por defecto, que pueden cambiarse.\n \n Al hacer clic derecho sobre el nombre de un grupo, aparecen las opciones de cambiar el nombre o el ícono. Hay algunos nombres que estan reservados y además los nombres de grupos no se pueden repetir. Mas aún, entre los nombres de grupos, cámaras, grillas y emaps no puede haber ningún nombre repetido.\n \n Los grupos se pueden eliminar haciendo clic derecho sobre el nombre. Para eliminar un grupo, este no debe contener ninguna cámara y ningún otro grupo.");
    }

    //<font color='red'>Nombre inválido</font>
    if(text == "Camaras"){
        ui->page->setText("<html>"
                          "<p>Para crear una cámara, se debe hacer clic derecho sobre el nombre de un grupo. "
                          "Se abrirá una ventana nueva con las configuraciones de la cámara,"
                          " divididas en las secciones:</p>"
                          "<p> <b>Generales</b>"
                          " \n - Nombre: El nombre que aparecerá en la lista de grupos y cámaras, en la interfaz."
                          " No puede contener espacios, y no puede repetir el nombre de alguna otra cámara, grupo,"
                          " grilla o emap. \n - Dirección: Dirección RTSP o HTTP para conectarse con el stream de"
                          " la cámara. \n - Espejar y rotar: Habilita o deshabilita las transformaciones visuales"
                          " de la cámara. \n - Buscar: \n Cuando no se conoce la dirección rtsp o http de una cámara"
                          ", se la puede buscar ingresando la ip, puerto, usuario, password y la marca fabricante"
                          " de la cámara. Al hacer clic en el botón de buscar, se lee una lista de posibles"
                          " direcciones para esa cámara, de un archivo llamado sources. Puede tardar varios minutos "
                          "en encontrar las direcciones. \n \n Si se desconoce la marca del fabricante puede ponerse"
                          " la opción Desconocido, pero se tarda mas en encontrar las direcciones."
                          " Cuando encuentre direcciones válidas, se debe hacer doble clic para seleccionarla"
                          " y previsualizarla.</p>"
                          "<p> <b>Recorte:</b> "
                          "Esta pestaña aparece solo cuando se crea una subcámara, para elegir la parte de la "
                          "cámara padre que va a tomar la subcámara.</p>"

                          " \n \n Grabar video: \n - Grabar: Habilita o deshabilita la grabación de la cámara "
                          "\n - Disminuir FPS: Si esta activado, los fps de los videos que se graben de esa "
                          "cámara disminuyen considerablemente. Esto significa que los videos resultantes se "
                          "verán mucho menos fluidos, pero el tamaño en disco que ocuparán sera mucho menor. "
                          "\n - Grabar en ciclos: Si se activa esta opción, se puede elegir un tamaño máximo "
                          "de espacio que ocuparán los videos de la cámara. Al superar este espacio, se reemplazan "
                          "los videos mas antiguos. \n - Programado: si se activa esta opción, se puede elegir "
                          "los días y horarios en que se va a grabar la cámara. Si esta deshabilitada esta opción,"
                          " se graba siempre. \n - Detectar movimiento: Si se activa esta opción, "
                          "solo se grabará la cámara cuando se detecte algún movimiento. \n - Usar máscara: "
                          "Si esta activada esta opción, se detectará movimiento solamente en el area seleccionada "
                          "en azul en Definir máscara. \n - Sensibilidad: Sensibilidad de la detección de"
                          " movimiento. Mientas mayor sea la sensibilidad, se detectarán movimientos menores. "
                          "Si la sensibilidad es muy baja, solo detectara movimientos grandes. \n - Umbral: "
                          "Define la diferencia en colores que debe haber para considerar que hay movimiento."
                          " \n Fotogramas: Define la cantidad de fotogramas hacia atras que se ven para detectar "
                          "el movimiento. Si los fotogramas son pocos, los movimientos mas lentos se vuelven "
                          "inperceptibles. Mientras que una mayor cantidad de fotogramas permite percibir "
                          "movimientos mas largos en el tiempo, pero tambien los cambios de luz del día. \n \n Alertas:"
                          "/html>");
    }

    if(text == "PTZ"){
        ui->page->setText("");
    }
    if(text == "Buscar dispositivos"){
        ui->page->setText("");
    }
    if(text == "Grillas"){
        ui->page->setText("");
    }
    if(text == "Emaps"){
        ui->page->setText("");
    }
    if(text == "Logs"){
        ui->page->setText("");
    }
    if(text == "Configuraciones globales"){
        ui->page->setText("");
    }
    if(text == "Re-streaming"){
        ui->page->setText("Funcion no disponible.");
    }


    if(text == "Errores comunes"){
        ui->page->setText(
        "\nLas cámaras se conectan y desconectan todo el tiempo"
        "\nPuede ser que la cámara tenga (de fábrica) un número limitado de retransmisiones. Este error ocurre cuando se supera este número. Para solucionar esto se puede crear una retransmisión local que tiene un número ilimitado clientes. (Herramientas->Retransmitir videos)."
        "\n"
        "\nLas cámaras se ven con poca calidad/resolución"
        "\nCompruebe, cuando crea una cámara, que la resolución del stream de video es el de mayor calidad que brinda la cámara. Si no, pruebe otra dirección de stream (rtsp)."
        "\nRecuerde que algunas configuraciones de calidad y resolución de las cámaras solo pueden modificarse desde el panel de configuraciones provisto por el fabricante."
        "\n"
        "\nLas cámaras se ven lentas"
        "\nCuando se ven pocos fotogramas por segundo en las visualizaciones de las cámaras, es probable que sea porque el uso de la memoria del CPU es excesivo. "
        "\nConsulte sobre las características recomendadas para su ordenador, según la cantidad y calidad de las cámaras y visualizaciones que necesita."
        "\nPara reducir la memoria utilizada por el programa, utilize grillas con mas visualizaciones pero mas pequeñas, y evite utilizar grillas en ventanas independientes. En lugar de eso, utilize pestañas en la ventana principal."
        "\n"
        "\nNo se cambia el nombre de un grupo, grilla o emap"
        "\nEsto ocurre cuando se elige un nombre inválido. No se permiten espacios, y algunos caracteres especiales. Además, no se permite repetir nombres entre grupos, cámaras, grillas y emaps."
        "\n"
        "\nNo se encuentran las cámaras al buscar dispositivos"
        "\nLos motivos pueden ser:"
        "\n1. La máquina no esta conectada a la red donde se encuentran las cámaras. "
        "\n2. Las cámaras no son ONVIF."
        "\n3. El tránsito en la red es lento."
        "\n"
        "\nLas cámaras no se estan grabando"
        "\nUna vez que se agrega una cámara con ciertas configuraciones de grabación, se debe comenzar a grabar desde alguna instancia cualquiera de vCenterManager. Si no se esta grabando puede ser por la programación o detección de movimiento que esten configurados. "
        "\n"
        "\nEn el caso de la detección de movimiento, puede ser que la sensibilidad esté alta y por ese motivo no detecta el movimiento y no graba."
        "\n"
        "\nNo puedo eliminar un grupo"
        "\nPara eliminar un grupo, este no debe tener sub-grupos o cámaras. Elimine primero los elementos \"hijos\"."
        "\n"
        "\nNo puedo eliminar una camara"
        "\nPara eliminar una cámara, esta no debe tener sub-cámaras. Elimine primero las sub-cámaras."
        "\n"
        "\nEl programa se cierra inesperadamente"
        "\nLos motivos por los que esto puede suceder son:"
        "\n1. Se perdió la conexión con el KeyManager."
        "\n2. Se perdió la conexión con la base de datos."
        "\n3. Hay información inválida en la base de datos."
        "\n4. No hay memoria disponible suficiente para la ejecución del programa."
        "\n5. El mismo usuario ingresó desde otra instancia del vCenterViewer."
        "\n"
        "\nNo se guardan las grillas y/o emaps al reiniciar el programa"
        "\nLas grillas y emaps se guardan por usuario, si ingresa con un usuario distinto, las grillas y emaps cambian. "
        "\nPor otro lado, si alguna grilla que esta en una ventana independiente se cierra, se elimina de las configuraciones de ese usuario y no se puede recuperar. Para guardar las grillas independientes al cerrar el programa, se debe cerrar desde la ventana principal sin cerrar las otras."
        "\n"
        "\nNo puedo ver los logs locales"
        "\nAl iniciar el programa, elija un directorio válido para guardar los logs locales. La ventana de previsualización de logs busca los archivos de logs que estén en esa carpeta. "
        "\nLos logs que se hayan guardado en otra carpeta, solo podrán verse desde el gestor de archivos de su sistema operativo, con algún editor de textos."
        "\n"
        "\nNo puedo ver la lista de alertas"
        "\nLa lista de alertas puede separarse de la ventana principal y puede moverse y cerrarse. Si no la ve, pruebe Ver->Lista de Alertas en el menú, o Ver->Reestablecer."
        "\n"
        "\nNo puedo ver el plan de acción de una alerta"
        "\nPara ver el plan de acción de una alerta, debe hacer doble clic sobre ella en la lista de alertas. Si esto no funciona, no hay ningún plan de alerta cargado en la base de datos para ese caso."
        "\n"
        "\nNo funciona el PTZ de una cámara"
        "\nCuando configure el PTZ de una cámara ONVIF, pruebe si funcionan los botones de esa ventana. Si no, alguno de los parámetros (IP,Puerto,Usuario,Password) es incorrecto o no se tienen los permisos para manejar el PTZ con ese usuario. Recuerde que si la cámara no utiliza el protocolo ONVIF, no podrá manejarla."
        "\n"
        "\nLa ventana se oscurece por un tiempo cuando creo, modifico o elimino una camara"
        "\nEsto sucede cuando la conexión con dicha camara es lenta o nula. El programa se puede detener unos segundos, y despues continua su ejecución."
        "\n"
        "\nNo se ve la previsualizacion de la cámara mientras la configuro o creo"
        "\nA veces, las cámaras que no estan siendo visualizadas en alguna grilla no se actualizan. Si en la ventana de configuración no se ve el video, pruebe cerrar la ventana de configuración, luego arrastrar la cámara a una grilla visible, y finalmente volver a abrir la ventana de configuración. "
        "\nPara la creación de las sub-cámaras es lo mismo, si la cámara padre no esta activa en alguna grilla visible, puede ser que no se vea la previsualización y no se pueda hacer el recorte."
        "\n");
    }
}

void Manual::on_pushButton_clicked() {
    log("Se cierra ventana: Manual");
    this->close();
}
