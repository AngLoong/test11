# include "hbs1096c_logmsg.h"

#include <iostream>
#include <stdio.h>
#include <QDateTime>

//#include "hbs1096c_file.h"

using std::cout;
using std::endl;

void LogPrint(QString str) {
    cout<<endl;
    cout<<TEXT_LOGMSG_HEADER<<str.toStdString()<<endl;
    cout<<endl;
}

void LogPrintHex(char hex) {
    cout<<endl;
    cout<<TEXT_LOGMSG_HEADER<<"HEX:"<<endl;
    printf("%x",hex);
    cout<<endl;
}

QString LogDateTime(void) {
    QDateTime temp_qdtCurrentTime=QDateTime::currentDateTime();
    QString temp_qsCurrentTime=temp_qdtCurrentTime.toString("hh:mm yyyy-MM-dd");
    return temp_qsCurrentTime;
}

//void LogExportToFile(QString str) {
//    WriteTextToFile(FILE_LOG_LOGMSG,str);
//}
