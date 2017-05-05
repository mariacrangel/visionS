#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <iostream>
#include <istream>
#include <fstream>

#include <QDialog>
#include <QCloseEvent>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class StartWindow;
}

extern std::string BASE_DIR;
extern std::string mongo_addr;
extern std::string key_addr;
extern QString screenshots_folder;
extern QString logs_folder;
extern QString curr_style;

extern bool startwindowclosed;
extern bool cerrar;

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();
    void saveAndClose();
private slots:
    void on_accept_clicked();
    void closeEvent(QCloseEvent *event);
    void on_set_snapshots_dir_clicked();
    void on_set_logs_dir_clicked();

private:
    Ui::StartWindow *ui;
    bool accepted_;
};

#endif // STARTWINDOW_H
