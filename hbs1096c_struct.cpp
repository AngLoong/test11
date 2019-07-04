#include "hbs1096c_struct.h"

#include <QVector>

#include "hbs1096c_sql.h"
#include "hbs1096c_logmsg.h"

QVector <FilterPara> g_filter_para;
DebugPara g_debug_para;
CurrentData g_current_data;

int g_iFd; //信号板串口通讯
//int g_fd_online;//联机串口通讯

int FilterDataInit(FilterData * filter_data) {
    filter_data->count = 4;
    filter_data->dual = 0;
    filter_data->current_first = 2;
    filter_data->current_second = 0;
    filter_data->num_1_name = "405";
    filter_data->num_2_name = "450";
    filter_data->num_3_name = "492";
    filter_data->num_4_name = "630";
    filter_data->num_5_name = "empty";
    filter_data->num_6_name = "empty";
    filter_data->num_7_name = "empty";
    filter_data->num_8_name = "empty";
    filter_data->num_9_name = "empty";
    filter_data->num_10_name = "empty";
    filter_data->num_11_name = "empty";
    filter_data->num_12_name = "empty";
    filter_data->num_13_name = "empty";
    filter_data->num_14_name = "empty";
    filter_data->num_15_name = "empty";
    return 0;
}

int FilterParaInit(QVector <FilterPara> * para) {
    para->clear();
    FilterPara temp_filter_para;
    temp_filter_para.num = 1;
    temp_filter_para.name = "405";
    para->push_back(temp_filter_para);
    temp_filter_para.num = 2;
    temp_filter_para.name = "450";
    para->push_back(temp_filter_para);
    temp_filter_para.num = 3;
    temp_filter_para.name = "492";
    para->push_back(temp_filter_para);
    temp_filter_para.num = 4;
    temp_filter_para.name = "630";
    para->push_back(temp_filter_para);
    QString temp_str;
    temp_str = "count :";
    temp_str.append(QString::number(para->count()));
    temp_str.append("\n");
    temp_str.append(para->at(0).name).append("\n");
    temp_str.append(para->at(1).name).append("\n");
    temp_str.append(para->at(2).name).append("\n");
    temp_str.append(para->at(3).name).append("\n");
    LogPrint(temp_str);
    return 0;
}

int FilterStateInit(FilterState * state) {
    state->dual = 1;
    state->current_first = 1;
    state->current_second = 2;
    return 0;
}

int ItemParaInit(ItemPara * para) {
    para->item_id = 1;
    para->item_name = "";
    para->item_program = PROGRAM_NORMAL;
    para->item_type = ITEMTYPE_QUANTITATIVE;
    para->filter_dual = 0;
    para->filter_first = 1;
    para->filter_second = 2;
    para->x_axis = XAXIS_CONCENTRATION;
    para->y_axis = YAXIS_OD;
    para->std1_concentration = 1;
    para->std2_concentration = 2;
    para->std3_concentration = 3;
    para->std4_concentration = 4;
    para->std5_concentration = 5;
    para->std6_concentration = 6;
    para->std7_concentration = 7;
    para->std8_concentration = 8;

    para->negative_coefficient = 1;
    para->positive_coefficient = 0;
    para->cm_coefficient = 0;
    para->constant_term = 0;
    para->sign = SIGN_LESS;

    return 0;
}

int ReadPlateDataInit(ReadPlateData * read_plate_data) {
    read_plate_data->filter_dual = 0;
    read_plate_data->filter_first = 2;
    read_plate_data->filter_second = 0;
    read_plate_data->item_type = ITEMTYPE_OD;
    for(int i = 0;i < 12;i++) {
        for(int j = 0;j < 8;j++) {
            read_plate_data->table_od[i][j] = 0;
            read_plate_data->table_result[i][j] = -1;
            read_plate_data->table_layout_type[i][j] = LAYOUT_NONE;
            read_plate_data->table_layout_num[i][j] = -1;
        }
    }

    return 0;
}

int DebugParaInit(DebugPara * para_pt) {
    para_pt->plate_offset_opendoor = 24000;
    para_pt->plate_offset_blank = 9600;
    para_pt->plate_offset_test = 6080;
    para_pt->plate_offset_rest = 11840;
    return 0;
}

int CurrentDataInit(CurrentData * para_pt) {
    para_pt->filter_dua = false;
    para_pt->filter_first = 2;
    para_pt->filter_second = 4;
    para_pt->item_id = 1;
    return 0;
}

int QuantitativeParaInit(QuantitativePara * para_pt) {
    para_pt->para_a = 0;
    para_pt->para_b = 0;
    para_pt->para_r = 0;
    para_pt->x_axis = XAXIS_CONCENTRATION;
    para_pt->y_axis = YAXIS_OD;
    para_pt->std_concentration = new QVector<double>;
    para_pt->std_od = new QVector<double>;
    return 0;
}

int KineticsParaInit(KineticsPara * para_pt) {
    para_pt->counts = 5;
    para_pt->delay_min = 0;
    para_pt->delay_s = 10;
    para_pt->output_mode = KINETICS_OUTPUT_CSV_LOCAL;

    return 0;
}

int ShakeParaInit(ShakePara * para_pt) {
    para_pt->strength = 2;
    para_pt->time_s = 0;
    return 0;
}

int MeasureInformationInit(MeasureInformation * pt) {
    pt->id = 1;
    pt->date = "2018-01-01";
    pt->time = "12:12";
    pt->item_id = 1;
    pt->item_code = "HIV";
    pt->file_name = "1";
    return 0;
}

int FixParaInit(FixPara * pt) {
    for(int i = 0;i < 15;i++)
        pt->od_light[i] = 0;
    for(int i = 0;i < 8;i++)
        pt->ad_channel[i] = 0;
    return 0;
}

int DelayParaInit(DelayPara * pt) {
    pt->min = 0;
    pt->sec = 0;
    return 0;
}

int CustomLayoutDataInit(CustomLayoutData * pt) {
    for(int i = 0;i < 12;i++) {
        for(int j = 0;j < 8;j++) {
            pt->table_layout_type[i][j] = LAYOUT_NONE;
            pt->table_layout_num[i][j] = -1;
        }
    }
    return 0;
}

int CustomReadPlateDataInit(CustomReadPlateData * pt) {
    pt->filter_dual = 0;
    pt->filter_first = 2;
    pt->filter_second = 0;

    return 0;
}

int CustomCalculateDataInit(CustomCalculateData * pt) {
    pt->exp = "";
    return 0;
}

int CustomStepInit(CustomStep * pt) {
    pt->step_num = 1;
    pt->mode = CUSTOM_MODE_MEASURE;

    pt->read_plate_data.filter_dual = 0;
    pt->read_plate_data.filter_first = 2;
    pt->read_plate_data.filter_second = 4;

    pt->shake_para.strength = 1;
    pt->shake_para.time_s = 0;

    pt->delay_para.min = 0;
    pt->delay_para.sec = 0;

    pt->calculate.exp = "";

    return 0;
}

int CustomProgramInit(CustomProgram * pt) {
    pt->id = 0;
    pt->name = "    ";
    return 0;
}
