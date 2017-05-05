#ifndef LOGSWINDOW_H
#define LOGSWINDOW_H

#include <iostream>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QDate>
#include <QTextStream>
#include <QCloseEvent>

extern QString logs_folder;
extern void log(std::string log_msg);

namespace Ui {
class LogsWindow;
}

/*

LOGSWINDOW
  Ventana que permite visualizar los archivos de logs de todos los dias.
  Utiliza el directorio de logs que se configura al inicio, por lo tanto si el directorio se modifica, no se cargaran los archivos de los directorios anteriores.

*/
class LogsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogsWindow(QWidget *parent = 0);
    ~LogsWindow();
    void showLogs(QDate date);

private slots:
    void on_accept_clicked();
    void on_prev_day_clicked();
    void on_next_day_clicked();

    void closeEvent(QCloseEvent* event);

private:
    Ui::LogsWindow *ui;
    QDate date_shown;
};

#endif // LOGSWINDOW_H
