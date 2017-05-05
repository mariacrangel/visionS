#ifndef GROUPCONFIGDIALOG_H
#define GROUPCONFIGDIALOG_H

#include <QDialog>
#include <iostream>

extern void log(std::string log_msg);

namespace Ui {
class GroupConfigDialog;
}


/* Dialogo que permite configurar el icono y nombre de un grupo */
class GroupConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupConfigDialog(QWidget *parent = 0);
    ~GroupConfigDialog();

private:
    Ui::GroupConfigDialog *ui;
};

#endif // GROUPCONFIGDIALOG_H
