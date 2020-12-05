#include "stdio.h"
#include "stdbool.h"
#include "myBank.h"

double accounts[2][50];

//account openning
int open(double amount){
    int i = 0;
    while (accounts[0][i]!=0 && i<50)
    {
        i++;
    }
    if (i == 50){
        return -1;
    }
    accounts[0][i] = 1; 
    deposite(i+901, amount);
    return i+901;
}

bool isOpen(int account_number){
    if (accounts[0][account_number-901] == 0){
        return false;
    }
    return true;
    
}
//account balance
void balance(int account_number){
    if (!isOpen(account_number)){
        printf("This account is closed\n");
        return;
    }
    printf("The balance of account number %d is: %0.2f\n", account_number, accounts[1][account_number-901]);
}

//Deposite
void deposite(int account_number, double amount){
    if (!isOpen(account_number)){
        return;
    }
    accounts[1][account_number-901]+=amount;
    
}

//Money withdrawing. return updated balance
double withdrawing(int account_number, double amount){
    accounts[1][account_number-901] -= amount;
    return accounts[1][account_number-901];
}

//Closing account
void closing(int account_number){
        accounts[0][account_number-901] = 0;
        accounts[1][account_number-901] = 0;
}

//Insert rate for every account
void insert_rate(double interest_rate){
    int i = 901;
    while (i < 951)
    {
        if (isOpen(i))
        {
            accounts[1][i-901]*=(1+interest_rate/100);
        }
        i++; 
    } 
}

//Printing all the active account
void printing(){
    int i = 901;
    while ((i<951))
    {
        if (isOpen(i)){
            balance(i);
        }
        i++;
    }
}  

//Closing all the accounts
void Exit(){
    int i = 901;
    while ((i<951))
    {
        closing(i);
        i++;
    }
}


