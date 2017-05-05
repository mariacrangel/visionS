#ifndef MANUAL_H
#define MANUAL_H

#include <iostream>
#include <QDialog>

extern QString curr_style;
extern void log(std::string log_msg);

namespace Ui {
    class Manual;
}

class Manual : public QDialog {
    Q_OBJECT
public:
    explicit Manual(QWidget *parent = 0);
    ~Manual();

private slots:
    void on_list_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::Manual *ui;
};

#endif // MANUAL_H
