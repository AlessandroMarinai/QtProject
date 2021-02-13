#include "Date.h"

int Date::isLeapYear() const { //restituisce 1 se bisestile
    int y = this->year;
    int result = 0;
    if( y%4==0 ) {
        result = 1;
        if( y%100==0 && y%400!=0 ) {
            result = 0;
        }
    }
    return result;
}

int Date::getMonthLenght() const {
    int m = this->month;
    int result = 31;
    if ( m==4 || m==6 || m==9 || m==11 )
        result = 30;
    if ( m==2)
        result = 28 + this->isLeapYear();
    return result;
}

bool Date::isExistingDate() const {
    bool result = true;
    int d = this->day;
    int m = this->month; //uso queste variabili per evitare un'eccessiva verbosità
    if( d<1 || d>this->getMonthLenght() || m<1 || m>12)
        result = false;
    return result;
}

bool Date::operator<(const Date &right) const {
    bool result = true;
    if (year>right.year || (year==right.year && month>=right.month) ||
    (year==right.year && month==right.month && day>=right.day))
        result = false;
    return result;
}

bool Date::operator==(const Date &right) const {
    return year==right.year && month==right.month && day==right.day;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

