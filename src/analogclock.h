
#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif
