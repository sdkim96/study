#include <stdio.h>

enum dessert{
    DESSERT_CAKE,
    DESSERT_PIE,
    DESSERT_COOKIE,
};

enum korean_food{
    KOREAN_FOOD_BIBIMBAP,
    KOREAN_FOOD_BULGOGI,
    KOREAN_FOOD_KIMCHI,
};

int main(void)
{
    enum dessert my_dessert = DESSERT_PIE;
    enum korean_food my_korean_food = KOREAN_FOOD_BIBIMBAP;
    int is_same;


    printf("%d\n", my_dessert);
    printf("%d\n", my_korean_food);

    is_same = (my_dessert == my_korean_food);
    printf("is_same: %d\n", is_same);

    return 0;
}