#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
} date_t;

date_t make_day();
date_t* inject_today(date_t* dt);

int main(void)
{   
    date_t date;
    date = make_day();
    
    printf("Before: %d-%d-%d\n", date.year, date.month, date.day);
    inject_today(&date);

    printf("After: %d-%d-%d\n", date.year, date.month, date.day);
    
    return 0;
}

date_t make_day()
{
    date_t dt;
    dt.year = 0;
    dt.month = 0;
    dt.day = 0;
    return dt;
}

date_t* inject_today(date_t* dt)
{
    dt->year = 2021;
    dt->month = 10;
    dt->day = 10;
    return dt;
}