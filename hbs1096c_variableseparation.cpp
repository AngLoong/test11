#include "hbs1096c_variableseparation.h"

using std::cout;
using std::endl;

//int VariableSeparation(QString exp,QVector<VariablePara> * vpara_pt) {
//    VariablePara temp_para;
//    QVector<QString> temp_vexp;
//    QString temp_layout_type,temp_layout_num;
//    QString temp_layout,temp_step;
//    int ret,temp_step_num;

//    VariableSeparationToQS(exp,&temp_vexp);
//    for(int i = 0;i < temp_vexp.count();i ++) {
//        ret = StepLayoutSepara(temp_vexp.at(i),&temp_step,&temp_layout);
//        if(ret >= 0) {
//            temp_step_num = StepNumSepara(temp_step);
//            if(temp_step_num >= 0)
//                temp_para.step_num = temp_step_num;
//            ret = LayoutSepara(temp_layout,&temp_layout_type,&temp_layout_num);
//            if(ret >= 0) {
//                if(temp_layout_type == "STD")
//                    temp_para.layout_type = LAYOUT_STD;
//                else if(temp_layout_type == "NC")
//                    temp_para.layout_type = LAYOUT_NC;
//                else if(temp_layout_type == "PC")
//                    temp_para.layout_type = LAYOUT_PC;
//                else if(temp_layout_type == "CM")
//                    temp_para.layout_type = LAYOUT_CM;
//                temp_para.layout_num = temp_layout_num.toInt();
//            }

//        }
//    }
//}

int VariableExpToStruct(QString var_exp,VariablePara * para_pt) {
    QString temp_qs_arg1,temp_qs_arg2;
    QString temp_qs_var_type,temp_qs_var_num;
    int ret;
    bool ok;

    ret = StepLayoutSepara(var_exp,&temp_qs_arg1,&temp_qs_arg2);
    if(ret >= 0) {
        para_pt->step_num = StepNumSepara(temp_qs_arg1);
        if(para_pt->step_num < 0) {
            LogPrint("error : step num separa error!");

        } else {
            ret = SecondVariableSepara(temp_qs_arg2,&temp_qs_var_type,&temp_qs_var_num);
            if(ret >= 0) {
                if(temp_qs_var_type == "STD")
                    para_pt->var_type = VARIABLE_STD;
                else if(temp_qs_var_type == "NC")
                    para_pt->var_type = VARIABLE_NC;
                else if(temp_qs_var_type == "PC")
                    para_pt->var_type = VARIABLE_PC;
                else if(temp_qs_var_type == "CM")
                    para_pt->var_type = VARIABLE_CM;
                else if(temp_qs_var_type == "TIME")
                    para_pt->var_type = VARIABLE_TIME;
                else if(temp_qs_var_type == "OD")
                    para_pt->var_type = VARIABLE_OD;
                else {
                    LogPrint("ERROR: second variable separa error!");
                    ret = -1;
                }
                para_pt->var_num = temp_qs_var_num.toInt(&ok);
                if(!ok)
                   para_pt->var_num = -1;
            }

        }
    }
    return ret;
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

int SecondVariableSepara(QString exp,QString * type_pt,QString * num_pt) {
    int temp_num,ret;
    QString temp_qs_type=QString::null,temp_qs_num;

    temp_num = exp.indexOf("STD");
    if(temp_num >= 0) {
        temp_qs_type = "STD";
        temp_qs_num = exp.mid(3);
        ret = 1;
    }
//    temp_num = exp.indexOf("SMP");
//    if(temp_num >= 0) {
//        layout = "SMP";
//        num = exp.mid(3);
//    }
    temp_num = exp.indexOf("NC");
    if(temp_num >= 0) {
        temp_qs_type = "NC";
        temp_qs_num = exp.mid(2);
        ret = 2;
    }
    temp_num = exp.indexOf("PC");
    if(temp_num >= 0) {
        temp_qs_type = "PC";
        temp_qs_num = exp.mid(2);
        ret = 3;
    }
    temp_num = exp.indexOf("CM");
    if(temp_num >= 0) {
        temp_qs_type = "CM";
        temp_qs_num = exp.mid(2);
        ret = 4;
    }
    temp_num = exp.indexOf("OD");
    if(temp_num >= 0) {
        temp_qs_type = "OD";
        temp_qs_num = exp.mid(2);
    }
    temp_num = exp.indexOf("TIME");
    if(temp_num >= 0) {
        temp_qs_type = "TIME";
        temp_qs_num = exp.mid(4);
        ret = 5;
    }

    type_pt->clear();
    num_pt->clear();
    type_pt->append(temp_qs_type);
    num_pt->append(temp_qs_num);
    if(temp_qs_type.isNull()){
        cout<<"is null"<<endl;
        return -1;}
    else
        return ret;
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

int StepLayoutSepara(QString exp,QString * arg1_pt,QString * arg2_pt) {
    QString temp_step=QString::null,temp_layout;
    bool ok;

    exp.toDouble(&ok);
    if(ok)
        return -1;
    temp_step = exp.section('.',0,0);
    temp_layout = exp.section('.',1,1);
    arg1_pt->clear();
    arg2_pt->clear();
    arg1_pt->append(temp_step);
    arg2_pt->append(temp_layout);
    if(temp_step.count()<=1)
        return -1;
    else
        return 0;
}

