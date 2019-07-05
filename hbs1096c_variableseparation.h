#ifndef HBS1096C_VARIABLESEPARATION
#define HBS1096C_VARIABLESEPARATION

#include <QString>
#include <QVector>
#include <iostream>

#include "hbs1096c_struct.h"
#include "hbs1096c_logmsg.h"

enum TypeVariableCalculate {
    VARIABLE_STD = 1,
    VARIABLE_NC = 2,
    VARIABLE_PC = 3,
    VARIABLE_CM = 4,
    VARIABLE_TIME = 5,
    VARIABLE_OD = 6,
};

struct VariablePara{
  int step_num;
  TypeVariableCalculate var_type;
  int var_num;
};


extern int VariableSeparationToQS(QString exp,QVector<QString> * var);
extern int SecondVariableSepara(QString exp, QString * type_pt, QString * num_pt);
extern int StepLayoutSepara(QString exp, QString * arg1_pt, QString * arg2_pt);
extern int StepNumSepara(QString exp);
extern int VariableExpToStruct(QString var_exp,VariablePara * para_pt);
#endif // HBS1096C_VARIABLESEPARATION

