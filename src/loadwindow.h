#ifndef LOADWINDOW_H
#define LOADWINDOW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class LoadWindow;
}

class LoadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoadWindow(QWidget *parent = 0);
    ~LoadWindow();

private:
    Ui::LoadWindow *ui;
    QTimer* points_timer_;

public slots:
    void changePoints();
    void changeWhatIsLoading(QString message);
    void loadDone();
};

#endif // LOADWINDOW_H
