#ifndef HBS1096C_VARIABLESEPARATION
#define HBS1096C_VARIABLESEPARATION

#include <QString>
#include <QVector>
#include <iostream>

struct VariablePara{
  int step_num;
  int layout_type;
  int layout_num;
};


extern int VariableSeparationToQS(QString exp,QVector<QString> * var);
extern int LayoutSepara(QString exp, QString *layout_pt, QString *num_pt);
extern int StepLayoutSepara(QString exp,QString * step_pt,QString * layout_pt);
extern int StepNumSepara(QString exp);

#endif // HBS1096C_VARIABLESEPARATION

