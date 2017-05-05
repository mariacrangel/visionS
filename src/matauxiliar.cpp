#include "matauxiliar.h"


using namespace cv;
using namespace std;

// escribir texto en una imagen de opencv
void writeText(Mat img, string text, int x, int y, Scalar color,double fontscale) {
    int fontFace = FONT_ITALIC;
    int thickness = 1;
    int baseline=0;
    baseline += thickness;
    Point textOrg(x,y);
    putText(img, text, textOrg, fontFace, fontscale, color, thickness, 5);
}

// escribir REC junto a un circulo rojo, en una imagen de opencv
void drawRec(Mat &frame) {
    if(frame.cols>50){
        circle(frame,Point(frame.cols-35,frame.rows-24),5,Scalar(0,0,255),-1);
        writeText(frame,"REC",frame.cols-29,frame.rows-20,Scalar(0,0,255));
    }
}

// dibujar barra de movimiento
void drawMovBar(Mat &image, int mov_percent) {
    if(image.rows > 11 && image.rows > 11){
        double p = (double)mov_percent/100;
        int width = (double)image.cols*p*2;

        cv::Mat roi = image(cv::Rect(0, image.rows-10, min(width,(int)image.cols), 9));
        cv::Mat color(roi.size(), CV_8UC3, cv::Scalar(0, 125, 125));
        double alpha = 0.5;
        cv::addWeighted(color, alpha, roi, 1.0 - alpha , 0.0, roi);
    }
}

// escribir alerta
void writeAlert(Mat &frame, QString alert_msg) {
    if(frame.rows>50 && frame.cols>50)
        writeText(frame,alert_msg.toStdString(),10,frame.rows-20,Scalar(0,0,255));
}
