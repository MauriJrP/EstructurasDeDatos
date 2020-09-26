#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>
#include <ctime>

class Date
{
private:
  int day, month, year;
public:
  Date();
  Date(const Date&);

  int getDay() const;
  int getMonth() const;
  int getYear() const;

  std::string toString() const;

  void setDay( const int& );
  void setMonth( const int& );
  void setYear( const int& );

};

#endif // __DATE_H__