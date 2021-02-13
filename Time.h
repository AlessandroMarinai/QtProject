#ifndef QTHELLOWORLD_TIME_H
#define QTHELLOWORLD_TIME_H

class Time{
public:
    Time() = default;
    Time(int h, int m) : hour(h), minutes(m)  { };
    bool isExistingHour () const {
        bool result = true;
        int h = this->hour;
        int m = this->minutes;
        if (h<0 || h>23 || m<0 || m>59)
            result = false;
        return result;
    }

    bool operator==(const Time& right) const{
        return right.hour==hour && right.minutes==minutes;
    }

    bool operator<(const Time& right) const{
        bool result = true;
        if (hour>right.hour || (hour==right.hour && minutes>=right.minutes))
            result = false;
        return result;

    }

    int getHour() const {
        return hour;
    }

    int getMinutes() const {
        return minutes;
    }

private:
    int hour;
    int minutes;
};

#endif //QTHELLOWORLD_TIME_H
