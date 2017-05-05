#ifndef STYLECONFIGWINDOW_H
#define STYLECONFIGWINDOW_H
#include <fstream>
#include <QDialog>
#include <iostream>

extern std::string BASE_DIR;
extern int alert_items_max_font;
extern int alert_items_min_font;
extern int alerts_items_max_count;
extern QString alerts_items_color;

namespace Ui {
    class StyleConfigWindow;
}

class StyleConfigWindow : public QDialog {
    Q_OBJECT

public:
    explicit StyleConfigWindow(QWidget *parent = 0);
    ~StyleConfigWindow();

private slots:
    void on_aceptar_clicked();

private:
    Ui::StyleConfigWindow *ui;
};

#endif // STYLECONFIGWINDOW_H
