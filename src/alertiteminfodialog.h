#ifndef ALERTITEMINFODIALOG_H
#define ALERTITEMINFODIALOG_H

#include <opencv2/opencv.hpp>
#include <QDialog>
#include <QListWidgetItem>
#include <QDir>
#include <QFileInfoList>

struct AlertItem{
    QListWidgetItem* item;
    QString time;
    QString camera_name;
    QString msg;
    QString action_plan;
};

namespace Ui {
class AlertItemInfoDialog;
}

/*

  Dialogo que muestra la informacion de una alerta: la hora, camara, mensaje e imagen.

*/
class AlertItemInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlertItemInfoDialog(QWidget *parent = 0);
    ~AlertItemInfoDialog();
    void setAlertItem(AlertItem alert_item);
private slots:
    void on_aceptar_clicked();
private:
    Ui::AlertItemInfoDialog *ui;
};

#endif // ALERTITEMINFODIALOG_H
