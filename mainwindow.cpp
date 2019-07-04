#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "hbs-1096c_variableseparation.h"


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
    QString temp,dis,dis2,str2,lay_str,num_str,step_str,layout_str;
    QVector<QString> vstr;
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
    for(int i = 0;i < vstr.count();i++) {
        ret = StepLayoutSepara(vstr.at(i),&step_str,&layout_str);
        if(ret >= 0)
            dis2.append(step_str).append(">>").append(layout_str).append("\n");
    }
    ui->textBrowser->setText(dis2);

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
