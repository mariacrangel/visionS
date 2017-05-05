#ifndef DOUBLECALENDAR_H
#define DOUBLECALENDAR_H

#include <QDialog>
#include <QDate>

namespace Ui {
class DoubleCalendar;
}

class DoubleCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit DoubleCalendar(QWidget *parent = 0);
    ~DoubleCalendar();
    void setDays(QDate init,QDate end);

private:
    Ui::DoubleCalendar *ui;

signals:
    void newDays(QDate init, QDate end);
private slots:
    void on_save_clicked();
    void on_cancel_clicked();
};

#endif // DOUBLECALENDAR_H
