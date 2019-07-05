#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "hbs1096c_variableseparation.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString temp,dis,dis2,dis3,step_str,layout_str;
    QVector<QString> vstr;
    VariablePara var;
    double dtemp;
    bool ok;
    int ret;
    dis = "";
    temp = ui->lineEdit->text();
    VariableSeparationToQS(temp,&vstr);
    for(int i = 0;i < vstr.count();i ++) {
        dis.append(vstr.at(i)).append("\n");
    }
    ui->textEdit->setText(dis);
    dis2 = "";
    dis3 = "";
    for(int i = 0;i < vstr.count();i++) {
        ret = StepLayoutSepara(vstr.at(i),&step_str,&layout_str);
        if(ret >= 0){
            dis2.append(step_str).append(">>").append(layout_str).append("\n");
            VariableExpToStruct(vstr.at(i),&var);
            dis3.append("STEP->>").append(QString::number(var.step_num)).append("\n");
            switch(var.var_type) {
            case VARIABLE_STD:
                dis3.append("STD");
                dis3.append("-->").append(QString::number(var.var_num));
                break;
            case VARIABLE_NC:
                dis3.append("NC");
                break;
            case VARIABLE_PC:
                dis3.append("PC");
                break;
            case VARIABLE_CM:
                dis3.append("CM");
                break;
            case VARIABLE_TIME:
                dis3.append("TIME");
                break;
            case VARIABLE_OD:
                dis3.append("OD");
                break;
            default:
                break;
            }
            dis3.append("\n");

        } else {

        }

    }
    ui->textBrowser->setText(dis2);
    ui->textBrowser_2->setText(dis3);

//    dis2 = "";
//    for(int i = 0;i < vstr.count();i++) {
//        dtemp = vstr.at(i).toDouble(&ok);
//        str2 = QString::number(dtemp);
//        if(ok)
//            std::cout<<"num:"<<str2.toStdString()<<std::endl;
//        else {
//            ret = LayoutSepara(vstr.at(i),&lay_str,&num_str);
//            if(ret >= 0)
//                dis2.append(lay_str).append("::").append(num_str).append("\n");
//        }
//    }
//    ui->textBrowser->setText(dis2);
}
