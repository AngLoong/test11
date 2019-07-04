#ifndef HBS1096C_STRUCT_H
#define HBS1096C_STRUCT_H

#include <QString>
#include <QVector>


enum TypeItemType {
    ITEMTYPE_QUANTITATIVE=1,
    ITEMTYPE_QUALITATIVE=2,
    ITEMTYPE_OD=3,
    ITEMTYPE_OTHER = -1,
};

enum TypeProgram {
    PROGRAM_NORMAL = 1,
    PROGRAM_CUSTOM = 2,
};

enum TypeLayout {
    LAYOUT_NONE = 0,
    LAYOUT_BLANK = 1,
    LAYOUT_SMP = 2,
    LAYOUT_NC = 3,
    LAYOUT_PC = 4,
    LAYOUT_CM = 5,
    LAYOUT_STD = 6,
};

enum TypeNegativeSignInequality {
    SIGN_MORE = 1,
    SIGN_MORE_EQUAL = 2,
    SIGN_LESS = 3,
    SIGN_LESS_EQUAL = 4,
};

enum TypePolarity {
    POLARITY_POSITIVE=1,
    POLARITY_NEGATIVE=0,
    POLARITY_ERR=2,
};

enum TypeXAxis {
    XAXIS_CONCENTRATION=1,
    XAXIS_LOG=2,
};

enum TypeYAxis {
    YAXIS_OD=1,
    YAXIS_LOG=2,
    YAXIS_BI_B0=3,
};

enum TypeKineticsOutput {
    KINETICS_OUTPUT_232 = 1,
    KINETICS_OUTPUT_CSV_LOCAL = 2,
    KINETICS_OUTPUT_CSV_UDISK = 3,
    KINETICS_ONLINE_232 = 4,
};

enum TypeCustomStepMode {
    CUSTOM_MODE_NONE = 0,
    CUSTOM_MODE_MEASURE = 1,
    CUSTOM_MODE_DELAY = 2,
    CUSTOM_MODE_SHAKE = 3,
    CUSTOM_MODE_CALCULATE = 4,
};

struct FilterPara {
    int num;
    QString name;
};

struct FilterState {
    int dual;
    int current_first;
    int current_second;
};

struct FilterData
{
    int count;
    int dual;
    int current_first;
    int current_second;
    QString num_1_name;
    QString num_2_name;
    QString num_3_name;
    QString num_4_name;
    QString num_5_name;
    QString num_6_name;
    QString num_7_name;
    QString num_8_name;
    QString num_9_name;
    QString num_10_name;
    QString num_11_name;
    QString num_12_name;
    QString num_13_name;
    QString num_14_name;
    QString num_15_name;
};

struct ReadPlateData {
    int filter_dual;
    int filter_first;
    int filter_second;
    TypeItemType item_type;
    double table_od[12][8];
    double table_result[12][8];
    TypeLayout table_layout_type[12][8];
    int table_layout_num[12][8];

};

struct ItemPara {
    int item_id;
    TypeItemType item_type;
    QString item_name;
    TypeProgram item_program;
    int filter_dual;
    int filter_first;
    int filter_second;
    TypeXAxis x_axis;
    TypeYAxis y_axis;

    double std1_concentration;
    double std2_concentration;
    double std3_concentration;
    double std4_concentration;
    double std5_concentration;
    double std6_concentration;
    double std7_concentration;
    double std8_concentration;

    double negative_coefficient;
    double positive_coefficient;
    double cm_coefficient;
    double constant_term;
    TypeNegativeSignInequality sign;
};

struct MeasureInformation {
    int id;
    QString date;
    QString time;
    int item_id;
    QString item_code;
    QString file_name;

};

struct QuantitativePara {
    QVector <double> *std_concentration;
    QVector <double> *std_od;
    TypeXAxis x_axis;
    TypeYAxis y_axis;
    double para_a;
    double para_b;
    double para_r;
};

struct QualitativePara {
    double negative_coefficient;
    double positive_coefficient;
    double cm_coefficient;
    double Constant_term;
    TypeNegativeSignInequality sign;

    double negative_od;
    double positive_od;
    double cm_od;

    double cutoff_value;
};

struct DebugPara {
    int plate_offset_opendoor;
    int plate_offset_blank;
    int plate_offset_test;
    int plate_offset_rest;
};

struct CurrentData {
    bool filter_dua;
    int filter_first;
    int filter_second;
    int item_id;
};

struct KineticsPara {
    int counts;
    int delay_min;
    int delay_s;
    TypeKineticsOutput output_mode;

};

struct ShakePara {
    int strength;
    int time_s;
};

struct DelayPara {
    int min;
    int sec;
};

struct FixPara {
    double od_light[15];
    int ad_channel[8];
};

struct CustomLayoutData {
  TypeLayout table_layout_type[12][8];
  int table_layout_num[12][8];
};

struct CustomReadPlateData {
    int filter_dual;//1:dual  0:sign
    int filter_first;
    int filter_second;
    //TypeItemType item_type;
    double * table_od[12][8];
    //double table_result[12][8];
};

struct CustomCalculateData {
    TypeItemType item_type;
    QString exp;
};

struct CustomStep {
    int step_num;
    TypeCustomStepMode mode;
    //MeasureInformation * info_pt;
    CustomReadPlateData read_plate_data;
    //KineticsPara * kinetics_para_pt;
    ShakePara shake_para;
    DelayPara delay_para;
    CustomCalculateData calculate;
};

struct CustomProgram {
    int id;
    QString name;
    QVector <CustomStep> steps;
};

extern QVector <FilterPara> g_filter_para;
extern DebugPara g_debug_para;
extern CurrentData g_current_data;

extern int g_iFd;

extern int FilterDataInit(FilterData * filter_data);
extern int ItemParaInit(ItemPara * para);
extern int FilterParaInit(QVector <FilterPara> * para);
extern int FilterStateInit(FilterState * state);
extern int DebugParaInit(DebugPara * para_pt);
extern int CurrentDataInit(CurrentData * para_pt);
extern int ReadPlateDataInit(ReadPlateData * read_plate_data);
extern int QuantitativeParaInit(QuantitativePara * para_pt);
extern int MeasureInformationInit(MeasureInformation * pt);
extern int KineticsParaInit(KineticsPara * para_pt);
extern int ShakeParaInit(ShakePara * para_pt);
extern int FixParaInit(FixPara * pt);
extern int CustomProgramInit(CustomProgram * pt);
extern int CustomStepInit(CustomStep * pt);

#endif // HBS1096C_STRUCT_H
