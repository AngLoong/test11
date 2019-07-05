#ifndef HBS1096C_LOGMSG
#define HBS1096C_LOGMSG

#include <QString>

#define TEXT_LOGMSG_HEADER "*****"

extern void LogPrint(QString str);
extern QString LogDateTime(void);
extern void LogExportToFile(QString str);
extern void LogPrintHex(char hex);

#endif // HBS1096C_LOGMSG

