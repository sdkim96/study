#include <stdio.h>

size_t boss = 0;

int find_next_dungeon(void);
int spawn_monster(void);

int main(void) 
{
    /*  
        The order of function calls is not guaranteed
    */
    if (find_next_dungeon() + spawn_monster() == 2) {
        printf("You are ready to fight the boss\n");
    }
}

int find_next_dungeon(void)
{
    printf("find_next_dungeon called\n");
    boss++;
    return 1;
}

int spawn_monster(void)
{   
    if (boss == 1) {
        printf("boss is already spawned\n");
        return 1;
    } else {
        printf("boss is not ready\n");
        return 0;
    }
}