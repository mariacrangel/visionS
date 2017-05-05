#include "maskwidget.h"
#include "ui_maskwidget.h"

using namespace cv;
using namespace std;

MaskWidget::MaskWidget(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::MaskWidget) {
    ui->setupUi(this);
    image_set_ = false;

    for(int i=0;i<15*12;i++)
        selection_.push_back(false);

    for(int i=0;i<15*12;i++)
        loaded_selection_.push_back(false);

    // inicializar labels
    for(uint i=0;i<15;i++)
        for(uint j=0;j<12;j++){
            QLabel* newlabel = new QLabel(this);

            ui->gridLayout0->addWidget(newlabel,j,i);
            all_labels_.push_back(newlabel);
        }
}

QImage matToQImage(const Mat& mat){
    const uchar *qImageBuffer = (const uchar*)mat.data;
    QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    return img.rgbSwapped();
}

void MaskWidget::setImage(Mat img){

    Mat r_img;
    cv::resize(img,r_img,cv::Size(570,440));
    image_ = r_img;

    int subimage_w = r_img.cols/15;
    int subimage_h = r_img.rows/12;
    vector<Mat> subimages;

    // partir imagen en 15*12 subimagenes
    for(int i=0;i<15;i++)
        for(uint j=0;j<12;j++){
            Mat subimage(r_img,cv::Rect(i*subimage_w,j*subimage_h,subimage_w,subimage_h));
            subimages.push_back(subimage);
        }

    for(uint i=0;i<all_labels_.size();i++){
        Mat subimg = subimages[i];
        QImage qimg = matToQImage(subimg);
        all_labels_[i]->setPixmap(QPixmap::fromImage(qimg));
    }

    image_set_ = true;

}

vector<bool> hexToBoolVec(string hex){

    vector<bool> selections;
    for(uint i=0;i<hex.size();i++){
        char c = hex[i];
        string binary_str;
        switch(c)
        {
            case '0':
            binary_str = "0000";
            break;
            case '1':
            binary_str = "0001";
            break;
            case '2':
            binary_str = "0010";
            break;
            case '3':
            binary_str = "0011";
            break;
            case '4':
            binary_str = "0100";
            break;
            case '5':
            binary_str = "0101";
            break;
            case '6':
            binary_str = "0110";
            break;
            case '7':
            binary_str = "0111";
            break;
            case '8':
            binary_str = "1000";
            break;
            case '9':
            binary_str = "1001";
            break;
            case 'A':
            binary_str = "1010";
            break;
            case 'B':
            binary_str = "1011";
            break;
            case 'C':
            binary_str = "1100";
            break;
            case 'D':
            binary_str = "1101";
            break;
            case 'E':
            binary_str = "1110";
            break;
            case 'F':
            binary_str = "1111";
            break;
        }
        for(int b=0;b<4;b++)
            if(binary_str[b] == '0')
                selections.push_back(false);
            else
                selections.push_back(true);
    }
    return selections;
}

string boolVecToHex(vector<bool> bs){
    string hex = "";

    for(uint i=0;i<bs.size();i+=4){

        // pasar de 4 booleanos a 4 bits (ceros y unos)
        string binary_str = "";
        for(int j=0;j<4;j++)
            if(bs[i+j] ==true)
                binary_str += "1";
            else
                binary_str += "0";

        // pasar de cadena de 4 bits a letra
        if(binary_str=="0000")hex+="0";
        if(binary_str=="0001")hex+="1";
        if(binary_str=="0010")hex+="2";
        if(binary_str=="0011")hex+="3";
        if(binary_str=="0100")hex+="4";
        if(binary_str=="0101")hex+="5";
        if(binary_str=="0110")hex+="6";
        if(binary_str=="0111")hex+="7";
        if(binary_str=="1000")hex+="8";
        if(binary_str=="1001")hex+="9";
        if(binary_str=="1010")hex+="A";
        if(binary_str=="1011")hex+="B";
        if(binary_str=="1100")hex+="C";
        if(binary_str=="1101")hex+="D";
        if(binary_str=="1110")hex+="E";
        if(binary_str=="1111")hex+="F";

    }
    return hex;

}


void MaskWidget::setSelection(string hex){

    if(hex != ""){
        selection_ = hexToBoolVec(hex);
        loaded_selection_ = selection_;

        for(uint i=0;i<selection_.size();i++){
            selectLabel(i,selection_[i]);
        }
    }
}

void MaskWidget::selectLabel(int index,bool select){
    if(index != -1){
        int subimage_w = image_.cols/15;
        int subimage_h = image_.rows/12;

        int row = index%12;
        int col = index/12;

        Mat subimage(image_.clone(),cv::Rect(col*subimage_w,row*subimage_h,subimage_w,subimage_h));

        if(select){
            subimage = subimage + Scalar(90,0,0) - Scalar(0,90,90);
            selection_[index]=true;
        }else{
            selection_[index]=false;
        }

        QImage qimg = matToQImage(subimage);
        all_labels_[index]->setPixmap(QPixmap::fromImage(qimg));
    }
}

int MaskWidget::getLabelIndexByGlobalPos(QPoint globalPos){

    for(uint i=0;i<all_labels_.size();i++){

        QPoint cv_tl(all_labels_[i]->x(),all_labels_[i]->y());
        QPoint cv_br(all_labels_[i]->x()+all_labels_[i]->width(),all_labels_[i]->y()+all_labels_[i]->height());

        QPoint global_cv_tl = mapToGlobal(cv_tl);
        QPoint global_cv_br = mapToGlobal(cv_br);

        if(globalPos.x() >= global_cv_tl.x() &&
           globalPos.x() < global_cv_br.x() &&
           globalPos.y() >= global_cv_tl.y() &&
           globalPos.y() < global_cv_br.y())
        {
            return i;
        }
    }

    return -1;
}

void MaskWidget::mouseMoveEvent(QMouseEvent *event){
        QPoint globalpos = mapToGlobal(event->pos());
        selectLabel(getLabelIndexByGlobalPos(globalpos),select_mode_);
}

void MaskWidget::mousePressEvent(QMouseEvent *event){

    if(event->button()==Qt::LeftButton){
        QPoint globalpos = mapToGlobal(event->pos());
        selectLabel(getLabelIndexByGlobalPos(globalpos),true);
        select_mode_ = true;
    }else{
        QPoint globalpos = mapToGlobal(event->pos());
        selectLabel(getLabelIndexByGlobalPos(globalpos),false);
        select_mode_ = false;
    }

}

MaskWidget::~MaskWidget(){
    delete ui;
}

void MaskWidget::on_savemask_clicked(){

    string hex_mask = boolVecToHex(selection_);
    emit newMask(hex_mask);
    this->close();

}

void MaskWidget::on_reest_clicked()
{
    selection_ = loaded_selection_;

    for(uint i=0;i<selection_.size();i++)
        selectLabel(i,selection_[i]);


}

void MaskWidget::on_removeall_clicked()
{

    for(uint i=0;i<selection_.size();i++)
        selection_[i]=false;

    for(uint i=0;i<selection_.size();i++)
        selectLabel(i,selection_[i]);
}

void MaskWidget::on_selectall_clicked()
{

    for(uint i=0;i<selection_.size();i++)
        selection_[i]=true;

    for(uint i=0;i<selection_.size();i++)
        selectLabel(i,selection_[i]);
}
