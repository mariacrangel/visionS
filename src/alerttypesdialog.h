#ifndef ALERTTYPESDIALOG_H
#define ALERTTYPESDIALOG_H

#include <iostream>
#include <QDialog>

namespace Ui {
class AlertTypesDialog;
}

class AlertTypesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlertTypesDialog(QWidget *parent = 0);
    ~AlertTypesDialog();
    void setAlerts(std::vector<std::pair<std::string, int>> alerts);

private:
    Ui::AlertTypesDialog *ui;
};

#endif // ALERTTYPESDIALOG_H
