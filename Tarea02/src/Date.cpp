#include "../include/Date.h"

using namespace std;

Date::Date()
{
  time_t timeNow;
  time(&timeNow);
  struct tm *myTime = localtime(&timeNow);
  day = myTime->tm_mday;
  month = myTime->tm_mon+1;
  year = myTime->tm_year+1900;
}

Date::Date(const Date &date) : day(date.day), month(date.month), year(date.year) {}

int Date::getDay() const
{
  return day;
}

int Date::getMonth() const
{
  return month;
}

int Date::getYear() const
{
  return year;
}

std::string Date::toString() const
{
  return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

void Date::setDay(const int &_day)
{
  _day >= 1 && _day <= 7 ? day = _day : day;
}

void Date::setMonth(const int &_month)
{
  _month >= 1 && _month <= 12? month = _month : month;
}

void Date::setYear(const int &_year)
{
  _year >= year && _year < 3000 ? year = _year : year;
}
