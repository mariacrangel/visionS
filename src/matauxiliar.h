#ifndef MATAUXILIAR_H
#define MATAUXILIAR_H

#include <iostream>
#include <QString>
#include <opencv2/opencv.hpp>

/*
    Funciones para dibujar/escribir en matrices de opencv
*/

void writeText(cv::Mat img, std::string text, int x, int y, cv::Scalar color, double fontscale=0.4);
void drawRec(cv::Mat &frame);
void drawMovBar(cv::Mat &image, int mov_percent);
void writeAlert(cv::Mat &frame, QString alert_msg);

#endif // MATAUXILIAR_H
