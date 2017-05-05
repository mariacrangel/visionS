#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include <QDate>

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = 0);
    ~Calendar();
    void setDate(QDate newdate);
signals:
    void newDate(QDate);
private slots:
    void on_accept_clicked();

    void on_cancel_clicked();

private:
    Ui::Calendar *ui;
};

#endif // CALENDAR_H
