#include "schedulerwidget.h"
#include "ui_schedulerwidget.h"

using namespace std;

SchedulerWidget::SchedulerWidget(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::SchedulerWidget) {
    ui->setupUi(this);
    loaded_scheduler_ = "";

    for(int row=0;row<24;row++){
        for(int col=0;col<7;col++){
            ui->tableWidget->setItem(row, col, new QTableWidgetItem);
            ui->tableWidget->item(row, col)->setBackground(Qt::black);
        }
    }
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 7pt; }");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView { font-size: 7pt; }");
    log("Se abre ventana: Scheduler");
}

string boolsToHex(vector<bool> bs){
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

vector<bool> hexToBools(string hex){

    vector<bool> selections;
    for(uint i=0;i<hex.size();i++){
        char c = hex[i];
        string binary_str;
        switch(c)
        {
            case '0': binary_str = "0000";
            break;
            case '1': binary_str = "0001";
            break;
            case '2': binary_str = "0010";
            break;
            case '3': binary_str = "0011";
            break;
            case '4': binary_str = "0100";
            break;
            case '5': binary_str = "0101";
            break;
            case '6': binary_str = "0110";
            break;
            case '7': binary_str = "0111";
            break;
            case '8': binary_str = "1000";
            break;
            case '9': binary_str = "1001";
            break;
            case 'A': binary_str = "1010";
            break;
            case 'B': binary_str = "1011";
            break;
            case 'C': binary_str = "1100";
            break;
            case 'D': binary_str = "1101";
            break;
            case 'E': binary_str = "1110";
            break;
            case 'F': binary_str = "1111";
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

void SchedulerWidget::setScheduler(string scheduler){
    loaded_scheduler_ = scheduler;

    vector<bool> selections = hexToBools(scheduler);

    // seleccionar
    for(uint i=0;i<selections.size();i++){
        int row = i%24;
        int column = i/24;
        if(selections[i] == true){
            ui->tableWidget->setItemSelected(ui->tableWidget->item(row,column),true);
        }else{
            ui->tableWidget->setItemSelected(ui->tableWidget->item(row,column),false);
        }
    }

}

SchedulerWidget::~SchedulerWidget(){
    delete ui;
}

void SchedulerWidget::on_load_clicked(){
    setScheduler(loaded_scheduler_);
}

string SchedulerWidget::getHexFromtable(){
    vector<bool> selected;
    for(int col=0;col<7;col++){
        for(int row=0;row<24;row++){
            if(ui->tableWidget->item(row,col)->isSelected()){
                selected.push_back(true);
            }else{
                selected.push_back(false);
            }
        }
    }
    return boolsToHex(selected);
}

void SchedulerWidget::on_save_clicked(){

    // se emite una senal para que la ventana de configuracion actualize el scheduler
    string newscheduler = getHexFromtable();
    emit newScheduler(newscheduler);
    this_thread::sleep_for(std::chrono::milliseconds(50));

    // se cierra la ventana
    log("Se cierra ventana: Scheduler");
    this->close();
}
