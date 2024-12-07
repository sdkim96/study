#include <studio.h>
#include "account.h"

static unsigned int balance = 0;

unsigned int get_current_balance(const char user[])
{
    printf("User: %s\n", user);
    return balance;
}


void deposit(const unsigned int amount)
{
    printf("Deposit: %d\n", amount);
    balance += amount;
}

void withdraw(const unsigned int amount)
{
    printf("Withdraw: %d\n", amount);
    balance -= amount;
}