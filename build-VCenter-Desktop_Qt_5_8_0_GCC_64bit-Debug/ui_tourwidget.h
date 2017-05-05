/********************************************************************************
** Form generated from reading UI file 'tourwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURWIDGET_H
#define UI_TOURWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TourWidget
{
public:
    QGridLayout *gridLayout;
    QListWidget *preset_list;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *save;
    QVBoxLayout *verticalLayout;
    QPushButton *add_tour_item;
    QPushButton *remove_tour_item;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *start_tour;
    QListWidget *tour_list;
    QLabel *label_3;
    QGridLayout *gridLayout_2;
    QPushButton *ptz_left;
    QPushButton *ptz_up;
    QLineEdit *new_preset_name;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *add_preset;
    QSpacerItem *horizontalSpacer;
    QPushButton *ptz_right;
    QPushButton *pushButton;
    QPushButton *update_preset_list;
    QPushButton *ptz_down;
    QPushButton *ptz_in;
    QPushButton *ptz_out;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLabel *camera_ip;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *camera_port;

    void setupUi(QDialog *TourWidget)
    {
        if (TourWidget->objectName().isEmpty())
            TourWidget->setObjectName(QStringLiteral("TourWidget"));
        TourWidget->resize(427, 458);
        QFont font;
        font.setPointSize(8);
        TourWidget->setFont(font);
        gridLayout = new QGridLayout(TourWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        preset_list = new QListWidget(TourWidget);
        preset_list->setObjectName(QStringLiteral("preset_list"));
        preset_list->setFont(font);

        gridLayout->addWidget(preset_list, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        save = new QPushButton(TourWidget);
        save->setObjectName(QStringLiteral("save"));
        save->setFont(font);

        horizontalLayout->addWidget(save);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        add_tour_item = new QPushButton(TourWidget);
        add_tour_item->setObjectName(QStringLiteral("add_tour_item"));
        add_tour_item->setMinimumSize(QSize(25, 25));
        add_tour_item->setMaximumSize(QSize(25, 25));

        verticalLayout->addWidget(add_tour_item);

        remove_tour_item = new QPushButton(TourWidget);
        remove_tour_item->setObjectName(QStringLiteral("remove_tour_item"));
        remove_tour_item->setMinimumSize(QSize(25, 25));
        remove_tour_item->setMaximumSize(QSize(25, 25));

        verticalLayout->addWidget(remove_tour_item);

        pushButton_2 = new QPushButton(TourWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(25, 25));
        pushButton_2->setMaximumSize(QSize(25, 25));
        pushButton_2->setFont(font);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(TourWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(25, 25));
        pushButton_3->setMaximumSize(QSize(25, 25));
        pushButton_3->setFont(font);

        verticalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(verticalLayout, 4, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        start_tour = new QPushButton(TourWidget);
        start_tour->setObjectName(QStringLiteral("start_tour"));
        start_tour->setMinimumSize(QSize(90, 0));
        start_tour->setMaximumSize(QSize(90, 16777215));
        QFont font1;
        font1.setPointSize(7);
        start_tour->setFont(font1);

        gridLayout_3->addWidget(start_tour, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 5, 2, 1, 1);

        tour_list = new QListWidget(TourWidget);
        tour_list->setObjectName(QStringLiteral("tour_list"));
        tour_list->setFont(font);

        gridLayout->addWidget(tour_list, 4, 2, 1, 1);

        label_3 = new QLabel(TourWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ptz_left = new QPushButton(TourWidget);
        ptz_left->setObjectName(QStringLiteral("ptz_left"));
        ptz_left->setMinimumSize(QSize(25, 25));
        ptz_left->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral("../images/icon/ptz_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptz_left->setIcon(icon);
        ptz_left->setFlat(true);

        gridLayout_2->addWidget(ptz_left, 2, 1, 1, 1);

        ptz_up = new QPushButton(TourWidget);
        ptz_up->setObjectName(QStringLiteral("ptz_up"));
        ptz_up->setMinimumSize(QSize(25, 25));
        ptz_up->setMaximumSize(QSize(25, 25));
        QFont font3;
        font3.setFamily(QStringLiteral("Sawasdee"));
        ptz_up->setFont(font3);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../images/icon/ptz_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptz_up->setIcon(icon1);
        ptz_up->setFlat(true);

        gridLayout_2->addWidget(ptz_up, 1, 2, 1, 1);

        new_preset_name = new QLineEdit(TourWidget);
        new_preset_name->setObjectName(QStringLiteral("new_preset_name"));

        gridLayout_2->addWidget(new_preset_name, 4, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        add_preset = new QPushButton(TourWidget);
        add_preset->setObjectName(QStringLiteral("add_preset"));
        add_preset->setFont(font1);

        gridLayout_2->addWidget(add_preset, 5, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 4, 1, 1);

        ptz_right = new QPushButton(TourWidget);
        ptz_right->setObjectName(QStringLiteral("ptz_right"));
        ptz_right->setMinimumSize(QSize(25, 25));
        ptz_right->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../images/icon/ptz_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptz_right->setIcon(icon2);
        ptz_right->setFlat(true);

        gridLayout_2->addWidget(ptz_right, 2, 3, 1, 1);

        pushButton = new QPushButton(TourWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font1);

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 3);

        update_preset_list = new QPushButton(TourWidget);
        update_preset_list->setObjectName(QStringLiteral("update_preset_list"));
        update_preset_list->setFont(font1);

        gridLayout_2->addWidget(update_preset_list, 0, 4, 1, 1);

        ptz_down = new QPushButton(TourWidget);
        ptz_down->setObjectName(QStringLiteral("ptz_down"));
        ptz_down->setMinimumSize(QSize(25, 25));
        ptz_down->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../images/icon/ptz_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptz_down->setIcon(icon3);
        ptz_down->setFlat(true);

        gridLayout_2->addWidget(ptz_down, 3, 2, 1, 1);

        ptz_in = new QPushButton(TourWidget);
        ptz_in->setObjectName(QStringLiteral("ptz_in"));
        ptz_in->setMinimumSize(QSize(25, 25));
        ptz_in->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../images/icon/ptz_zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptz_in->setIcon(icon4);
        ptz_in->setFlat(true);

        gridLayout_2->addWidget(ptz_in, 1, 4, 1, 1);

        ptz_out = new QPushButton(TourWidget);
        ptz_out->setObjectName(QStringLiteral("ptz_out"));
        ptz_out->setMinimumSize(QSize(25, 25));
        ptz_out->setMaximumSize(QSize(25, 25));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../images/icon/ptz_zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptz_out->setIcon(icon5);
        ptz_out->setFlat(true);

        gridLayout_2->addWidget(ptz_out, 3, 4, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 0, 1, 1);

        label = new QLabel(TourWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 8, 1, 1, 1);

        camera_ip = new QLabel(TourWidget);
        camera_ip->setObjectName(QStringLiteral("camera_ip"));
        camera_ip->setFont(font);

        gridLayout->addWidget(camera_ip, 6, 2, 1, 1);

        label_2 = new QLabel(TourWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 2, 1, 1);

        label_4 = new QLabel(TourWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        camera_port = new QLabel(TourWidget);
        camera_port->setObjectName(QStringLiteral("camera_port"));
        camera_port->setFont(font);

        gridLayout->addWidget(camera_port, 7, 2, 1, 1);


        retranslateUi(TourWidget);

        QMetaObject::connectSlotsByName(TourWidget);
    } // setupUi

    void retranslateUi(QDialog *TourWidget)
    {
        TourWidget->setWindowTitle(QApplication::translate("TourWidget", "Definir tour", Q_NULLPTR));
        save->setText(QApplication::translate("TourWidget", "Guardar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        add_tour_item->setToolTip(QApplication::translate("TourWidget", "<html><head/><body><p>Agregar</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        add_tour_item->setText(QApplication::translate("TourWidget", ">", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        remove_tour_item->setToolTip(QApplication::translate("TourWidget", "<html><head/><body><p>Borrar</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        remove_tour_item->setText(QApplication::translate("TourWidget", "<", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("TourWidget", "<html><head/><body><p>Agregar todos en orden</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("TourWidget", ">>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("TourWidget", "<html><head/><body><p>Borrar todos</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("TourWidget", "<<", Q_NULLPTR));
        start_tour->setText(QApplication::translate("TourWidget", "Comenzar tour", Q_NULLPTR));
        label_3->setText(QApplication::translate("TourWidget", "IP", Q_NULLPTR));
        ptz_left->setText(QString());
        ptz_up->setText(QString());
        add_preset->setText(QApplication::translate("TourWidget", "Nuevo preset", Q_NULLPTR));
        ptz_right->setText(QString());
        pushButton->setText(QApplication::translate("TourWidget", "Ir a preset", Q_NULLPTR));
        update_preset_list->setText(QApplication::translate("TourWidget", "Actualizar", Q_NULLPTR));
        ptz_down->setText(QString());
        ptz_in->setText(QString());
        ptz_out->setText(QString());
        label->setText(QApplication::translate("TourWidget", "Presets", Q_NULLPTR));
        camera_ip->setText(QString());
        label_2->setText(QApplication::translate("TourWidget", "Tour", Q_NULLPTR));
        label_4->setText(QApplication::translate("TourWidget", "Puerto", Q_NULLPTR));
        camera_port->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TourWidget: public Ui_TourWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURWIDGET_H
