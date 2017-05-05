/********************************************************************************
** Form generated from reading UI file 'manual.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUAL_H
#define UI_MANUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Manual
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *page;
    QListWidget *list;
    QLabel *label_2;
    QLabel *title;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Manual)
    {
        if (Manual->objectName().isEmpty())
            Manual->setObjectName(QStringLiteral("Manual"));
        Manual->resize(915, 570);
        Manual->setMinimumSize(QSize(915, 570));
        Manual->setMaximumSize(QSize(915, 570));
        QFont font;
        font.setPointSize(8);
        Manual->setFont(font);
        gridLayout = new QGridLayout(Manual);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Manual);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 3, 3, 1, 1);

        pushButton = new QPushButton(Manual);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(pushButton, 3, 6, 1, 1);

        pushButton_2 = new QPushButton(Manual);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(22, 22));
        pushButton_2->setMaximumSize(QSize(22, 22));
        QFont font1;
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 3, 5, 1, 1);

        pushButton_3 = new QPushButton(Manual);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(22, 22));
        pushButton_3->setMaximumSize(QSize(22, 22));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_3->setFont(font2);

        gridLayout->addWidget(pushButton_3, 3, 1, 1, 1);

        page = new QTextEdit(Manual);
        page->setObjectName(QStringLiteral("page"));
        page->setMinimumSize(QSize(700, 500));
        page->setMaximumSize(QSize(700, 500));
        page->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        page->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        page->setReadOnly(true);

        gridLayout->addWidget(page, 1, 1, 1, 6);

        list = new QListWidget(Manual);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        list->setObjectName(QStringLiteral("list"));
        list->setMinimumSize(QSize(100, 500));
        list->setMaximumSize(QSize(200, 500));

        gridLayout->addWidget(list, 1, 0, 1, 1);

        label_2 = new QLabel(Manual);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 4, 1, 1);

        title = new QLabel(Manual);
        title->setObjectName(QStringLiteral("title"));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        title->setFont(font3);

        gridLayout->addWidget(title, 0, 1, 1, 5);

        label_3 = new QLabel(Manual);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 3, 1, 1);

        label_4 = new QLabel(Manual);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 2, 1, 1);


        retranslateUi(Manual);

        QMetaObject::connectSlotsByName(Manual);
    } // setupUi

    void retranslateUi(QDialog *Manual)
    {
        Manual->setWindowTitle(QApplication::translate("Manual", "Manual", Q_NULLPTR));
        label->setText(QApplication::translate("Manual", "P\303\241gina 1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Manual", "Cerrar", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Manual", ">", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Manual", "<", Q_NULLPTR));
        page->setHtml(QApplication::translate("Manual", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">vCenterViewer</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">Manual</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">0. Inicio</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Cuando se inicia el vCenterViewer, se deben configurar algunos parametros iniciales locales, que se guardan y cargan de los archivos de configuraci\303\263n del sistema.</p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/new/prefix1/manual/configuraciones_iniciales.png\" /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">0.1 IP Key Manager</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">La IP en que se inici\303\263 el programa vKey (si es el mismo ordenador, la IP ser\303\241 127.0.0.1). El vKey es el programa que controla la licencia de todos los demas programas de VisionStudio. Si el vKey no se encuentra activo, el vCenterViewe"
                        "r no puede iniciar. Adem\303\241s, el vCenterViewer prueba conectar con el vKey peri\303\263dicamente, y si no puede hacerlo se cierra autom\303\241ticamente.  Por defecto el puerto de comunicaci\303\263n que utiliza el vKey es el 1883. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">0.2 IP Mongo DB</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">La IP en que se encuentra la base de datos donde se guarda toda la informaci\303\263n del sistema y los eventos. Se utiliza una \303\272nica base de datos a la que se conectan todos los programas y todos los ordenadores. Por defecto, el puerto que utiliza MongoDB para conectar con las bases de datos es 27017.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight"
                        ":600;\">0.3 Carpeta de snapshots</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Elija una carpeta donde se guardaran todas las imagenes de los snapshots, junto con la hora exacta y el nombre de la c\303\241mara correspondiente.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">0.4 Carpeta de Logs</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Elija una carpeta donde se guardaran los archivos de Logs. Los logs contienen toda la informaci\303\263n de la actividad realizada por los usuarios en el vCenterViewer, y adem\303\241s contienen informaci\303\263n extra que sirve para obtener ayuda de los desarrolladores en caso de que ocurra alg\303\272n error en la aplicaci\303\263n. Los logs son archivos de texto y se guardan u"
                        "no por d\303\255a. Mientras la carpeta donde se guarden sea la misma, desde el vCenterViewer se pueden leer los logs del mismo d\303\255a y de los d\303\255as anteriores.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">1. Usuarios\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace'; font-weight:600;\">1.1 Inicio de sesi\303\263n</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">Al iniciar el VCenterViewer, debe ingresarse un usuario y contrase\303\261a v\303\241lidos. Los usuarios se crean \303\272nicamente por la interfaz web.</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/new/prefix1/manual/inicio_de_sesion.png\" /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace'; font-weight:600;\">1.2 Guardar datos</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">Las grillas, ventanas y emaps que el usuario cree, asi como las configuraciones de playback, le pertenecen solamente a ese usuario y se guardan en la base de datos inmediatamente cada vez que hay un cambio.<br />Esto es, cuando un usuario cierra sesi\303\263n se guardan todas las visualizaciones, y cuando vuelve a iniciar sesi\303\263n vuelve a ver las mismas grillas y emaps.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><"
                        "span style=\" font-family:'monospace'; font-weight:600;\">1.3 Permisos</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">Cuando se crea un usuario desde la interfaz web, se pueden cambiar los permisos del mismo y las c\303\241maras asignadas.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">Cada usuario tiene un conjunto de grupos de c\303\241maras disponibles para visualizar, y tiene permisos distintos para cambiar las configuraciones globales y las configuraciones de las c\303\241maras.<br /><br />Los permisos son:<br />- Cambiar configuraciones globales<br />- Configuraciones avanzadas de c\303\241maras: comprende todas las configuraciones de las c\303\241maras. Adem\303\241s, se permite crear nuevas c\303\241maras y grupos.<br />- Configuraciones b\303"
                        "\241sicas de c\303\241maras: comprende solo las configuraciones de visualizaci\303\263n y de PTZ.<br />- Retransmitir videos.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">2. Interfaz</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">La interfaz del VCenterViewer esta compuesta por:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">- La barra de men\303\272.<br />- Una lista de grupos de c\303\241maras en la parte izquierda, con la cual se puede agregar, quitar y modificar c\303\241maras y grupos si se tienen los permisos. Tambien se permite arrastrar las c\303\241maras a las grillas para visualizarlas.<br />- Un c"
                        "uadro de pesta\303\261as en el centro, que agrupa las pesta\303\261as de grillas y emaps del usuario. Ver secciones Grillas y Emaps.<br />- Una barra de accesos r\303\241pidos, que contiene algunas funciones que estan disponibles tambien en la barra de men\303\272. \303\211sta se puede esconder o mover a gusto.<br />- Un Dock con la lista de alertas. Ver secci\303\263n Alertas.<br />- Un Dock para el manejo PTZ de las c\303\241maras Onvif.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">Las configuraciones de las grillas y emaps se guardan por usuario, en la base de datos. Mientras que las configuraciones de colores y del dock de alertas se guarda en los archivos locales de configuraci\303\263n. <br />Los docks pueden ocultarse, moverse, personalizarse y cambiar de monitor.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">3. Grupos \302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">Los grupos son contenedores de c\303\241maras, y de otros grupos.<br />Se puede crear un sub-grupo de un grupo ya existente, haciendo clic derecho sobre el mismo. <br />Cuando se crea un grupo, tiene un nombre y un \303\255cono por defecto, que pueden cambiarse. Al hacer clic derecho sobre el nombre de un grupo, aparecen las opciones de cambiar el nombre o el \303\255cono. Hay algunos nombres que estan reservados y adem\303\241s los nombres de grupos no se pueden repetir. Mas a\303\272n, entre los nombres de grupos, c\303\241maras, grillas y emaps no puede haber ning\303\272n nombre repetido.<br /><br />Los grupos se pueden eliminar haciendo clic derecho sobre el nombre. Para eliminar un grupo, este no debe contener ninguna c\303\241ma"
                        "ra y ning\303\272n otro grupo.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">4. C\303\241maras\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">4.1 Crear c\303\241maras</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para crear una c\303\241mara, si se tienen los privilegios, se debe hacer clic derecho sobre el nombre de un grupo. Se abrir\303\241 una ventana nueva con las configuraciones de la c\303\241mara, divididas en las secciones:</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">4.1.1 Generales</span></p>\n"
"<p style=\" margin-top:1"
                        "2px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Nombre: El nombre que aparecer\303\241 en la lista de grupos y c\303\241maras, en la interfaz. No puede contener espacios, y no puede repetir el nombre de alguna otra c\303\241mara, grupo, grilla o emap.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Direcci\303\263n: Direcci\303\263n RTSP o HTTP para conectarse con el stream de la c\303\241mara.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Espejar y rotar: Habilita o deshabilita las transformaciones visuales de la c\303\241mara. \\n - Buscar: \\n Cuando no se conoce la direcci\303\263n rtsp o http de una c\303\241mara , se la puede buscar ingresando la ip, puerto, usuario, password y la marca fabricante de la c\303\241mara. Al hacer clic en el bot\303\263n de buscar, se lee una lista de po"
                        "sibles direcciones para esa c\303\241mara, de un archivo llamado sources. Puede tardar varios minutos en encontrar las direcciones. \\n \\n Si se desconoce la marca del fabricante puede ponerse la opci\303\263n Desconocido, pero se tarda mas en encontrar las direcciones. Cuando encuentre direcciones v\303\241lidas, se debe hacer doble clic para seleccionarla y previsualizarla.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">4.1.2 Recorte</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Esta pesta\303\261a aparece solo cuando se crea una subc\303\241mara, para elegir la parte de la c\303\241mara padre que va a tomar la subc\303\241mara.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">4.1.3 Grab"
                        "ar video</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240- Grabar: Habilita o deshabilita la grabaci\303\263n de la c\303\241mara</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240- Disminuir FPS: Si esta activado, los fps de los videos que se graben de esa c\303\241mara disminuyen considerablemente. Esto significa que los videos resultantes se ver\303\241n mucho menos fluidos, pero el tama\303\261o en disco que ocupar\303\241n sera mucho menor.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Grabar en ciclos: Si se activa esta opci\303\263n, se puede elegir un tama\303\261o m\303\241ximo de espacio que ocupar\303\241n los videos de la c\303\241mara. Al superar este espacio, se reemplazan los videos mas antiguos.</p>\n"
"<p style=\" margin-top"
                        ":12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Programado: si se activa esta opci\303\263n, se puede elegir los d\303\255as y horarios en que se va a grabar la c\303\241mara. Si esta deshabilitada esta opci\303\263n, se graba siempre. Use el Ctrl+Clic Izquierdo para seleccionar y deseleccionar bloques por areas en la ventana de Modificar Scheduler.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Detectar movimiento: Si se activa esta opci\303\263n, solo se grabar\303\241 la c\303\241mara cuando se detecte alg\303\272n movimiento.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Usar m\303\241scara: Si esta activada esta opci\303\263n, se detectar\303\241 movimiento solamente en el \303\241rea seleccionada en azul en Definir m\303\241scara. Para seleccionar el \303\241rea use el clic derech"
                        "o e izquierdo del rat\303\263n.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Sensibilidad: Sensibilidad de la detecci\303\263n de movimiento. Mientas mayor sea la sensibilidad, se detectar\303\241n movimientos menores, pero puede detectar movimiento que no sean de inter\303\251s (movimiento de hojas por el viento, por ejemplo). Si la sensibilidad es muy baja, solo detectara movimientos grandes.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Umbral: Define la diferencia en colores que debe haber para considerar que hay movimiento.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Fotogramas: Define la cantidad de fotogramas hacia atras que se ven para detectar el movimiento. Si los fotogramas son pocos, los movimientos mas lentos se vuelven inperceptibles. Mi"
                        "entras que una mayor cantidad de fotogramas permite percibir movimientos mas largos en el tiempo, pero tambien los cambios de luz del d\303\255a.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Nota: los valores por defecto de la sensibilidad, umbral y fotogramas fueron probados en c\303\241maras HD para la detecci\303\263n de peatones, perros y veh\303\255culos en movimiento.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">4.1.4 Alertas</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Recibir alertas: Si esta opci\303\263n esta activa, se vincular\303\241 esta c\303\241mara con una instancia de alguna otra aplicaci\303\263n para recibir y guardar alertas.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:"
                        "0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Nombre de Instancia: El nombre con el que se llama a la instancia creada en la otra aplicaci\303\263n.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- IP: Direcci\303\263n IP donde esta ejecutando la otra aplicaci\303\263n.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-Producto: Seleccione de la lista, el producto que le corresponde a la otra aplicaci\303\263n de la cual recibir\303\241 las alertas. Si la lista aparece vac\303\255a, es porque a\303\272n no se cargaron los productos de la base de datos, cierre y vuelva a abrir la ventana de creaci\303\263n de la c\303\241mara. S\303\263lo apareceran los productos para los cuales posee licencias activas.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        ">Abajo aparecer\303\241 una lista con los tipos de alertas, los cuales puede filtrar para recibirlas selectivamente.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Enviar alertas: Agregue direcciones de correo y usuarios de telegram para que reciban ,por esos medios, las alertas. Agregue la cantidad que quiera.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para SMTP, las direcciones deben tener la forma completa: mail@mail.com. Y para Telegram, debe colocar el nombre de usuario con el cual inicia sesi\303\263n y NO el nombre p\303\272blico (por ejemplo, jperez puede ser el nombre de usuario y Juan Perez el nombre publico del perfil).</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">4.1.5 PTZ</span></p>\n"
"<p style=\" margin-top"
                        ":12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Activar PTZ: Si esta opci\303\263n esta activa y los datos de conexi\303\263n son correctos, podr\303\241 manejar el PTZ y los Tour de la c\303\241mara.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Conexi\303\263n: IP y puerto de conexi\303\263n ONVIF de la c\303\241mara. El puerto no es el mismo que se utiliza para obtener el stream, y suele ser 80.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Autenticaci\303\263n: Usuario y contrase\303\261a para conectarse a la c\303\241mara. Pueden ser distintos a los que usa para conectarse al stream. Si no le funcionan los mismos, pruebe usar la contrase\303\261a y/o usuario &quot;admin&quot;.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\">- Velocidad: La velocidad con la que se mover\303\241 o cambiar\303\241 el zoom la c\303\241mara.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Tiempo de movimiento (en segundos): el tiempo que se mover\303\241 la c\303\241mara cada vez que reciba una instrucci\303\263n.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Tour:  En esta ventana podr\303\241 ver los presets de la c\303\241mara, moverla, crear nuevos presets, y definir un tour.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para crear un preset nuevo primero mueva la c\303\241mara hacia la posici\303\263n que quiera, escriba un nombre v\303\241lido y presione &quot;Nuevo Preset&quot;. Luego Actualize la lista de presets para verlo.</p>\n"
"<p style=\" margin-top:12px; marg"
                        "in-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para crear un tour (recorrido), agregue los presets en orden en la lista derecha. Cada c\303\241mara puede guardar un tour.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para detener un tour, basta con mover la c\303\241mara hacia cualquier posici\303\263n. El tour puede volver a iniciarse con las mismas configuraciones en cualquier momento.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Tiempo de permanencia (en segundos): Tiempo que permanecer\303\241 la c\303\241mara en cada preset cuando est\303\251 realizando el tour.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">4.2 Subc\303\241maras</span></p>\n"
"<p style=\" margin-top:12px; marg"
                        "in-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Una subc\303\241mara o substream es simplemente un recorte de una c\303\241mara, que tiene sus propias configuraciones de grabacion y alertas. Comparte las configuraciones generales (excepto el nombre) y de PTZ de su c\303\241mara padre. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para crear una subc\303\241mara debe hacer clic derecho en el nombre de la camara padre en la lista de grupos y camaras. Se habilitar\303\241 la pesta\303\261a de Recorte, en la que debe dibujar con el rat\303\263n un rect\303\241ngulo del \303\241rea que abarcar\303\241 la nueva subc\303\241mara.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">5. Buscar dispositivos\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bo"
                        "ttom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hay dos formas de buscar dispositivos:</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">5.1 B\303\272squeda r\303\241pida</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Desde la barra de accesos r\303\241pidos o en Herramientas-&gt;Buscar dispositivos puede buscar todos los dispositivos ONVIF que se encuentren conectados en la red.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">5.2 Buscar direcciones de stream</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Desde la ventana de creaci\303\263n de c\303\241maras, puede bu"
                        "scar las direcciones RTSP o HTTP de cualquier c\303\241mara, ya sea ONVIF o no. Para esto necesita la IP, puerto (si es ONVIF generalmente el puerto es el 554), y un usuario y password con los permisos necesarios. Luego de setear estos par\303\241metros, haga clic en el bot\303\263n buscar. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Si conoce el fabricante de la c\303\241mara, la b\303\272squeda ser\303\241 mucho mas r\303\241pida. De lo contrario, puede llegar a tardar unos minutos en encontrar la direcci\303\263n de la c\303\241mara. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Puede arrojar varios resultados para una misma c\303\241mara, y cada uno de ellos puede tener diferentes configuraciones de resoluci\303\263n, calidad y formato.<br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -q"
                        "t-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">6. Grillas\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Puede crear nuevas grillas desde el men\303\272 de accesos r\303\241pidos o en Inicio-&gt;Nuevo-&gt;Grilla. Las grillas se crear\303\241n con un nombre por defecto que puede cambiarse desde el men\303\272 de clic derecho dentro de la grilla.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Antes de visualizar c\303\241maras en la grilla, debe seleccionar el tipo, utilizando los botones con dibujos de grillas en la parte inferior.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para visualizar c\303\241maras debe primero crearlas y luego arrastrarlas desde la lista de grupos y c\303\241maras. Las c\303\241mar"
                        "as en la grilla se pueden arrastrar para copiar, mover o reemplazar.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Desde el menu de clic derecho se pueden realizar otras acciones en la grilla:</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Zoom: Puede hacer un zoom r\303\241pido x2 o x4 en el lugar donde se hizo el clic derecho, y deshacerlo luego desde el mismo menu. El zoom solo se activa en la casilla seleccionada.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Capturar imagen: se guarda una imagen de la c\303\241mara seleccionada (en tama\303\261o original) en la carpeta de snapshots. El nombre de las imagenes guardadas contendr\303\241 la hora y nombre de la c\303\241mara.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px;\">- Independizar grilla: Elimina la pesta\303\261a de la grilla en la ventana principal y crea una copia de la grilla en una nueva ventana independiente, con las mismas funciones. Si esta nueva ventana se cierra, ya no se podr\303\241 recuperar. Para guardar la ventana independiente cuando cierre la sesi\303\263n, debe cerrar la aplicacion desde la ventana principal.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Mostrar u ocultar barra de playback: Si la c\303\241mara que esta siendo visualizada tiene activo el playback, muestra una barra de tiempo cuyo tama\303\261o depende del tama\303\261o del buffer de playback. Por defecto, se muestra la imagen actual de la c\303\241mara, y si se mueve la barra hacia la izquierda se mueve atras en el tiempo, segundo a segundo.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px;\">El playback se activa o desactiva haciendo clic derecho sobre el nombre de la c\303\241mara en la lista de grupos y camaras, y se configura desde Herramientas-&gt;Configuraciones de playback.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">7. EMaps\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Puede crear nuevas pesta\303\261as de EMaps desde el men\303\272 de accesos r\303\241pidos o en Inicio-&gt;Nuevo-&gt;EMap. El emap mostrar\303\241, en un principio, una imagen de muestra.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Se puede cambiar la imagen del EMap desde el menu del clic derecho dentro de la pesta\303\261a del EMap o arrastrando un archivo de imagen hacia la imagen actua"
                        "l.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pueden crearse cuantos EMaps se quieran y cada uno puede tener imagenes y c\303\241maras distintas.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Se pueden arrastrar las c\303\241maras hacia la imagen del EMap desde la lista de grupos y c\303\241maras. Los nombres de las c\303\241maras se dibujan en la imagen.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Al hacer clic izquierdo sobre el nombre de una c\303\241mara en la imagen, la misma se puede previsualizar en un tama\303\261o fijo. <br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">8. Logs\302\240</span></p>\n"
"<p style=\""
                        " margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Cada accion que el usuario activo realiza durante la ejecuci\303\263n del vCenterViewer es guardada localmente en archivos de texto con el nombre de logs. Se crea autom\303\241ticamente un archivo por d\303\255a y se puede acceder a ellos desde cualquier gestor de archivos o desde el mismo vCenterViewer, en la barra de accesos r\303\241pidos o en Herramientas-&gt;Logs.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Los archivos de logs contienen, ademas, la hora exacta en la que se ejecut\303\263 cada acci\303\263n. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Estos archivos sirven tambien como una ayuda ante alg\303\272n error que ocurra. Si el programa tiene algun error o se cierra inesperadamente, acuda a la ayuda de los desarrol"
                        "ladores con los archivos de log a mano.<br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">9. Configuraciones globales\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Las configuraciones globales se guardan en la base de datos y abarcan a todas las instancias de vCenterViewer y vCenterManager en el sistema. Se necesitan privilegios especiales para modificarlas.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para modificar las configuraciones globales, se debe acceder desde Herramientas-&gt;Configuraciones o desde el men\303\272 de accesos r\303\241pidos.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Entre las conf"
                        "iguraciones globales estan las de grabaci\303\263n: El tiempo de duraci\303\263n de cada archivo de video y la carpeta compartida donde se guardar\303\241n.<br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">10. Retransmiticiones\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">La retransmisi\303\263n de un stream de video sirve para disminuir el tiempo de obtenci\303\263n de las imagenes de las c\303\241maras que se encuentran alejadas espacialmente. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Cuando se retransmite un stream de una c\303\241mara de forma local, se gana en tiempo de espera, flujo de red y se obtiene una cantidad ilimitada de peticiones.</p>\n"
"<p style=\" margin-top:12px; marg"
                        "in-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Los re-streams se hacen desde el vCenterManager pero se configuran desde el vCenterViewer.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para iniciar o detener un re-stream, se debe acceder a la ventana de Retransmisiones desde el menu de accesos r\303\241pidos o desde Herramientas-&gt;Retransmitir videos.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para configurar un re-stream se necesita una direcci\303\263n RTSP o HTTP de donde se obtiene el video y un nombre para identificar el re-stream.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Una vez que se empieze a retransmitir, podr\303\241 ver en la tabla la direcci\303\263n nueva de video.<br /></p>\n"
"<p style=\" marg"
                        "in-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">Errores comunes</span></p></body></html>", Q_NULLPTR));

        const bool __sortingEnabled = list->isSortingEnabled();
        list->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = list->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Manual", "Usuarios", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = list->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Manual", "Interfaz", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = list->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Manual", "Grupos", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = list->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Manual", "Camaras", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = list->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Manual", "PTZ", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = list->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Manual", "Buscar dispositivos", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem6 = list->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Manual", "Grillas", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem7 = list->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("Manual", "Emaps", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem8 = list->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("Manual", "Logs", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem9 = list->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("Manual", "Configuraciones globales", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem10 = list->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("Manual", "Re-streaming", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem11 = list->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("Manual", "Errores comunes", Q_NULLPTR));
        list->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("Manual", "Siguiente", Q_NULLPTR));
        title->setText(QString());
        label_3->setText(QApplication::translate("Manual", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Manual", "Anterior", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Manual: public Ui_Manual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUAL_H
