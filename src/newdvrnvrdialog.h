#ifndef NEWDVRNVRDIALOG_H
#define NEWDVRNVRDIALOG_H

#include <QDialog>
#include <QCheckBox>

#include "group.h"
#include "dhdevice.h"

extern std::vector<Camera*> cameras;
extern bool validName(QString name);

namespace Ui {
class NewDVRNVRDialog;
}

class NewDVRNVRDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDVRNVRDialog(QWidget *parent = 0);
    ~NewDVRNVRDialog();
    void setGroup(Group* g);
    void setToConfigure(DhDevice* dev);

private:
    Ui::NewDVRNVRDialog *ui;
    Group* group_;

    bool configure_;
    bool connected_;
    DhDevice* device_;
    std::vector<std::string> channels_;
    void addChannelToGrid(int channel);

signals:
    void newDVRNVR(DhDevice *new_dvrnvr, Group *g, bool savetomongo);
private slots:
    void on_accept_clicked();
    void on_cancel_clicked();
    void on_connect_to_device_clicked();

};

#endif // NEWDVRNVRDIALOG_H
