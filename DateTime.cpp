// 
// 
// 

#include "DateTime.h"

DateTime::DateTime()
{
}

DateTime::~DateTime()
{
}

void DateTime::Init()
{
	Wire.begin();
	DS3231_init(DS3231_INTCN);
}

void DateTime::SetDateTime()
{
	DS3231_set(dateTimeStr);
}

void DateTime::SetDate(uint8_t dd, uint8_t mm, uint16_t yyyy )
{
	dateTimeStr.mday = dd;
	dateTimeStr.mon = mm;
	dateTimeStr.year = yyyy;
	DS3231_set(dateTimeStr);

}

void DateTime::SetTime(uint8_t hh, uint8_t mm, uint8_t ss)
{
	dateTimeStr.hour = hh;
	dateTimeStr.min = mm;
	dateTimeStr.sec = ss;
	DS3231_set(dateTimeStr);
}

void DateTime::GetDateTime()
{
	DS3231_get(&dateTimeStr);
}

void DateTime::GetDate()
{
}

void DateTime::GetTime()
{
}

String DateTime::ToString()
{
	return String(dateTimeStr.mday)+"."+ String(dateTimeStr.mon) + "." + String(dateTimeStr.year) + "  " +
                           String(dateTimeStr.hour) + ":" + String(dateTimeStr.min) + ":" + String(dateTimeStr.sec);
}



