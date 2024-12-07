#include <stdio.h>

#include "minions.h"

extern unsigned int g_hp;
extern unsigned int g_strength;

int main(void) 
{
    printf("g_hp: %d\n", g_hp);
    printf("g_strength: %d\n", g_strength);

    go_beserk();
    add_gold(100u);

    printf("g_hp: %d\n", g_hp);
    printf("g_strength: %d\n", g_strength);

    return 0;
}
