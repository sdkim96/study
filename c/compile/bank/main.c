#include <stdio.h>
#include "account.h"

int main(void)
{   
    unsigned int balance;
    balance = get_balance("Alice");

    printf("Current balance: %d\n", get_balance("Alice"));
    deposit(100);
    printf("Current balance: %d\n", get_balance("Alice"));
    withdraw(50);
    printf("Current balance: %d\n", get_balance("Alice"));

    return 0;
}
