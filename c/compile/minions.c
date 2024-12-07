#include <stdio.h>

#include "minions.h"

unsigned int g_hp = 100u;
unsigned int g_gold = 0u;
unsigned int g_strength = 10u;


void go_beserk(void)
{
    printf("minions go beserk\n");
    g_hp += 50u;
    g_strength += 10u;
}

void add_gold(unsigned int gold)
{
    printf("minions add gold: %d\n", gold);
    g_gold += gold;
}