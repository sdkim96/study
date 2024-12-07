#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

unsigned int get_balance(const char user[]);
void deposit(const unsigned int amount);
void withdraw(const unsigned int amount);

#endif /* BANK_ACCUOUNT_H */