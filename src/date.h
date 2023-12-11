#include "iostream"
#include "ctime"
#include "stringaddons.h"
/// @brief A class for date.
/// @return structure: year/month/day hour:minute:second
class date
{
public:
    void __re_alloc()
    {
        time_t ptr = time(0);
        tm *lt = localtime(&ptr);
        year = 1900 + lt->tm_year;
        month = lt->tm_mon;
        day = lt->tm_mday;
        hour = lt->tm_hour;
        minute = lt->tm_min;
        second = lt->tm_sec;
    }
    void __init()
    {

        time_t ptr = time(0);
        tm *lt = localtime(&ptr);
        year = 1900 + lt->tm_year;
        month = lt->tm_mon + 1;
        day = lt->tm_mday;
        hour = lt->tm_hour;
        minute = lt->tm_min;
        second = lt->tm_sec;
    }
    void print()
    {
        
    }

private:
    int year, month, day, hour, minute, second;
};