#ifndef MYBANK_H
#define MYBANK_H
#include <stdbool.h>
 
int open(double amount);
void balance(int account_number);
void deposite(int account_number, double amount);
double withdrawing(int account_number, double amount);
void closing(int account_number);
void insert_rate(double interest_rate);
void printing();
void Exit();
bool isOpen(int account_number);


#endif 