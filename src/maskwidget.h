#ifndef MASKWIDGET_H
#define MASKWIDGET_H

#include <QDialog>
#include <QLabel>
#include <QLayoutItem>
#include <QImage>
#include <iostream>
#include <QMouseEvent>

#include <opencv2/opencv.hpp>

namespace Ui {
    class MaskWidget;
}

class MaskWidget : public QDialog {
    Q_OBJECT

public:
    explicit MaskWidget(QWidget *parent = 0);
    ~MaskWidget();
    void setImage(cv::Mat img);

    void setSelection(std::string hex);

signals:
    void newMask(std::string mask);

private:
    Ui::MaskWidget *ui;
    std::vector<QLabel*> all_labels_;
    bool image_set_;
    cv::Mat image_;
    std::vector<bool> selection_;
    std::vector<bool> loaded_selection_;
    void selectLabel(int index, bool select);

    int getLabelIndexByGlobalPos(QPoint globalPos);
    bool select_mode_;

private slots:
    void mousePressEvent(QMouseEvent *event) /*Q_DECL_OVERRIDE*/;
    void mouseMoveEvent(QMouseEvent *event);
    void on_savemask_clicked();
    void on_reest_clicked();
    void on_removeall_clicked();
    void on_selectall_clicked();
};

#endif // MASKWIDGET_H
