#ifndef CONTACTO_H
#define CONTACTO_H

#include <QDialog>
#include "vsmongo.h"

extern VSMongo* vsmongo;

namespace Ui {
class Contacto;
}

/*

CONTACTO
  Dialogo que muestra la informacion de contacto

*/

class Contacto : public QDialog
{
    Q_OBJECT

public:
    explicit Contacto(QWidget *parent = 0);
    ~Contacto();

private slots:
    void on_aceptar_clicked();

private:
    Ui::Contacto *ui;
};

#endif // CONTACTO_H
