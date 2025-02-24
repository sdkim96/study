#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
} date_t;

void print_datetime_by_pointer(const date_t* dt)
{
    printf("%d-%d-%d\n", dt->year, dt->month, dt->day);
}


void print_datetime(date_t dt)
{
    printf("%d-%d-%d\n", dt.year, dt.month, dt.day);
}

int main(void)
{
    date_t dt;
    
    dt.year = 2021;
    dt.month = 10;
    dt.day = 10;

    print_datetime(dt);
    
    print_datetime_by_pointer(&dt);
    return 0;
}