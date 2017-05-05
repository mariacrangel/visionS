#ifndef RESTREAMSDIALOG_H
#define RESTREAMSDIALOG_H

#include <iostream>
#include <QDialog>
#include <QMenu>
#include <QModelIndex>
#include <QMessageBox>
#include <QCloseEvent>

#include "vsmongo.h"

extern VSMongo* vsmongo;
extern bool cerrar;
extern std::string exec_id;
extern QString icons_folder;

struct Restream{
    QString name;
    QString origen;
    QString destino;
};

namespace Ui {
class RestreamsDialog;
}

class RestreamsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RestreamsDialog(QWidget *parent = 0);
    ~RestreamsDialog();
public slots:
    void openMenu(QPoint p);
private slots:

    void on_new_restream_clicked();

    void on_accept_clicked();
    void closeEvent(QCloseEvent* event);

signals:
    void mongoDisconnected();

private:
    bool validName(QString name);
    bool validOrig(QString dir_origen);

    Ui::RestreamsDialog *ui;
    std::vector<MRestream *> m_restreams_;
    void updateTable();
    void loadRestreamsFromMongo();
};

#endif // RESTREAMSDIALOG_H
