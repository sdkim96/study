#include <stdio.h>

int calculate_risk(const int id);
int db_get_age(const int id);

int main(void)
{
    int id = 10;
    int risk = calculate_risk(id);
    printf("risk: %d\n", risk);

    return 0;
}

int calculate_risk(const int id)
{
    int age = db_get_age(id);
    /*
    this makes error during compiling
    */
    id *= 2;

    /*
    this makes error during compiling
    */
    const int age2 = db_get_age(id);
    age2 += 10;

    printf("age: %d\n", id);
    return age * id;

}

int db_get_age(const int id)
{
    return 30;
}