#include "hbs1096c_variableseparation.h"

using std::cout;
using std::endl;

int VariableSeparation(QString exp,QVector<VariablePara> * vpara_pt) {
    VariablePara temp_para;
    QVector<QString> temp_vexp;
    QString temp_layout_type,temp_layout_num;
    QString temp_layout,temp_step;
    int ret,temp_step_num;

    VariableSeparationToQS(exp,&temp_vexp);
    for(int i = 0;i < temp_vexp.count();i ++) {
        ret = StepLayoutSepara(temp_vexp.at(i),&temp_step,&temp_layout);
        if(ret >= 0) {
            temp_step_num = StepNumSepara(temp_step);
            if(temp_step_num >= 0)
                temp_para.step_num = temp_step_num;
            ret = LayoutSepara(temp_layout,&temp_layout_type,&temp_layout_num);
            if(ret >= 0) {
                if(temp_layout_type == "STD")
                    temp_para.layout_type = LAYOUT_STD;
                else if(temp_layout_type == "NC")
                    temp_para.layout_type = LAYOUT_NC;
                else if(temp_layout_type == "PC")
                    temp_para.layout_type = LAYOUT_PC;
                else if(temp_layout_type == "CM")
                    temp_para.layout_type = LAYOUT_CM;
                temp_para.layout_num = temp_layout_num.toInt();
            }

        }
    }
}

int VariableSeparationToQS(QString exp,QVector<QString> * var) {
    QString temp;
    QVector<int> symbol_num;
    for(int i = 0;i < exp.count();i ++) {
        if(exp.at(i) == '+' ||
           exp.at(i) == '-' ||
           exp.at(i) == '*' ||
           exp.at(i) == '/' ||
           exp.at(i) == '(' ||
           exp.at(i) == ')') {
            symbol_num.push_back(i);
        }
    }
    cout<<"symbol count:"<<symbol_num.count()<<endl;
    if(symbol_num.first() != 0) {
        temp = exp.left(symbol_num.first());
        var->push_back(temp);
    }
    for(int i = 0;i < symbol_num.count()-1;i ++) {
        temp = exp.mid(symbol_num.at(i),1);
        var->push_back(temp);
        temp = exp.mid(symbol_num.at(i)+1,symbol_num.at(i+1)-symbol_num.at(i)-1);
        if(!(temp.isEmpty()))
            var->push_back(temp);
    }
    if(symbol_num.last() == (exp.count()-1)) {
        temp = exp.right(1);
        var->push_back(temp);
    } else {
        temp = exp.mid(symbol_num.last(),1);
        var->push_back(temp);
        temp = exp.mid(symbol_num.last()+1);
        var->push_back(temp);
    }
    return 0;
}

int LayoutSepara(QString exp,QString * layout_pt,QString * num_pt) {
    int temp_num;
    QString layout=QString::null,num,sym;

    temp_num = exp.indexOf("STD");
    if(temp_num >= 0) {
        layout = "STD";
        num = exp.mid(3);
    }
//    temp_num = exp.indexOf("SMP");
//    if(temp_num >= 0) {
//        layout = "SMP";
//        num = exp.mid(3);
//    }
    temp_num = exp.indexOf("PC");
    if(temp_num >= 0) {
        layout = "PC";
        num = exp.mid(2);
    }
    temp_num = exp.indexOf("NC");
    if(temp_num >= 0) {
        layout = "NC";
        num = exp.mid(2);
    }
    temp_num = exp.indexOf("PC");
    if(temp_num >= 0) {
        layout = "PC";
        num = exp.mid(2);
    }
    temp_num = exp.indexOf("CM");
    if(temp_num >= 0) {
        layout = "CM";
        num = exp.mid(2);
    }

    cout<<"exp : "<<exp.toStdString()<<endl;
    cout<<"Layout : "<<layout.toStdString()<<endl;
    cout<<"NUM : "<<num.toStdString()<<endl;

    layout_pt->clear();
    num_pt->clear();
    layout_pt->append(layout);
    num_pt->append(num);
    if(layout.isNull()){
        cout<<"is null"<<endl;
        return -1;}
    else
        return 0;
}

int StepNumSepara(QString exp) {
    int temp_num,ret_num;
    QString step=QString::null,num;
    bool ok;

    temp_num = exp.indexOf("STEP");
    if(temp_num >= 0) {
        step = "STEP";
        num = exp.mid(4);
        ret_num = num.toInt(&ok);
    }
    if(step.isNull())
        return -1;
    else if(!ok)
        return -1;
    else
        return ret_num;
}

int StepLayoutSepara(QString exp,QString * step_pt,QString * layout_pt) {
    QString temp_step=QString::null,temp_layout;
    temp_step = exp.section('.',0,0);
    temp_layout = exp.section('.',1,1);
    step_pt->clear();
    layout_pt->clear();
    step_pt->append(temp_step);
    layout_pt->append(temp_layout);
    if(temp_step.count()<=1)
        return -1;
    else
        return 0;
}
