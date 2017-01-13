#ifndef ZTC_INCLUDE_ZTIME_H
#define ZTC_INCLUDE_ZTIME_H

#include <sys/timeb.h>
#include <time.h>
#include <string>
#include "ZMacroDefine.h"

BEGIN_ZTC_NAMESPACE;
using std::string;


class ZDateTime
{
public:
	ZDateTime();
	
	
	
	unsigned int msec;		///< ����
	unsigned short second;	///< ��(0-59)				
	unsigned short minute;	///< ��(0-59)				
	unsigned short hour;	///< ʱ(0-23)				
	unsigned short day;		///< ��(1-31)				
	unsigned short month;	///< ��(1-12)				
	unsigned short year;	///< ��(2000��ʾ2000��)		
	unsigned short weekDay;	///< ����					
	unsigned short yDay;	///< ���еĵڼ���			
	bool isDst;	///< ��ʱ��	
private:
	time_t m_time;
	tm *m_tm;
};

ZTC_API void getSystemDateTime(ZDateTime& dateTime);
ZTC_API unsigned long getTickCount();
ZTC_API unsigned long getThreadTime();

END_ZTC_NAMESPACE
#endif //ZTC_INCLUDE_ZTIME_H