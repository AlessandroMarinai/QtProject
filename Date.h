#ifndef QTHELLOWORLD_DATE_H
#define QTHELLOWORLD_DATE_H

#include "Time.h"

class Date {
public:
    Date()=default;
    Date(int da, int m, int y) : day(da), month(m), year(y) { };
    bool isExistingDate () const;
    int getMonthLenght () const;
    int isLeapYear() const ;

    bool operator<(const Date& right) const;
    bool operator==(const Date& right) const;

    int getDay() const;

    int getMonth() const;

    int getYear() const;

private:
    int day;
    int month;
    int year;
};


#endif //QTHELLOWORLD_DATE_H
