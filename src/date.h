#include "iostream"
#include "ctime"
#include "stringaddons.h"
/// @brief A class for date.
/// @return structure: year/month/day hour:minute:second
/*
*/
class date
{
public:
    void __update()
    {
        __init();
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
    void print() {
        // Year/Month/Day Hour:Minute:Second
        printf("%d/", year);
        if(month<10) {
            printf("0%d/", month);
        } else {
            printf("%d/", month);
        }
        if(day<10) {
            printf("0%d ", day);
        } else {
            printf("%d ", day);
        }
        if(hour<10) {
            printf("0%d:", hour);
        } else {
            printf("%d:", hour);
        }
        if(minute<10) {
            printf("0%d:", minute);
        } else {
            printf("%d:", minute);
        }
        if(second<10) { 
            printf("0%d", second);
        } else {
            printf("%d", second);
        }
        printf("\n");
    }
private:
    int year, month, day, hour, minute, second;
};