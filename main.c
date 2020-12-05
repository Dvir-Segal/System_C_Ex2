#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "myBank.h"

int main(){
char ch ='Q';

    while (ch!='E')
    {
        printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        scanf(" %c", &ch);
        int account_number;
        double amount, rate;
        switch (ch)
        {
        case 'O':
            printf("Please enter amount for deposit: "); 
            if(scanf("%lf",&amount)!=1){
                printf("Failed to read the amount\n");
                printf("\n");
                break;
            }
            if (amount<0)
            {
                printf("Invalid Amount\n");
                printf("\n");
                break;
            }
            int account = open(amount); 
            if (account == -1)
            {
                printf("Account openning is not possible because fulled capacity\n");
                printf("\n");
                break;
            }
            printf("New account number is: %d\n", account);
            printf("\n");
            break;
        case 'B':
            printf("Please enter account number: ");
            if(scanf("%d",&account_number)!=1){
                printf("Failed to read the account number\n");
                 printf("\n");
                break;
            }
            if (account_number < 901 || account_number > 950)
            {
                printf("the account is not real\n");
                printf("\n");
                break;
            }
            balance(account_number);
            printf("\n");
            break;
        case 'D':
            printf("Please enter account number: ");
            if(scanf("%d", &account_number)!=1){
                printf("Failed to read the account number\n");
                printf("\n");
                break;
            }
            if (account_number < 901 || account_number > 950)
            {
                printf("Invalid account number\n");
                printf("\n");
                break;
            }
            if(!isOpen(account_number)){
                printf("This account is closed\n");
                printf("\n");
                break;
            }
            printf("Please enter amount for deposit: ");
            if(scanf("%lf", &amount)!=1){
                printf("Failed to read the amount\n");
                printf("\n");
                break;
            }
            if (amount<0)
            {
                printf("Cannot deposit a negative amount\n");
                printf("\n");
                break;
            }
            deposite(account_number, amount);
            balance(account_number);
            printf("\n");
            break; 
        case 'W':
            printf("Please enter account number: ");
            if(scanf("%d",&account_number)!=1){
                printf("Failed to read the account number\n");
                printf("\n");
                break;
            }
             if (account_number < 901 || account_number > 950){
                printf("Invalid account number\n");
                printf("\n");
                break;
            }
            if (!isOpen(account_number)){
                printf("This account is closed\n");
                printf("\n");
                break;
            }
            printf("Please enter the amount to withdraw:");
            if(scanf("%lf",&amount)!=1){
                printf("Failed to read the account number\n");
                printf("\n");
                break;
            }
            if (amount<0){
                printf("Please insert real amount\n");
                printf("\n");
                break;
            }
            
            //If an exception is made, we will refund the money (withdrawal is not possible)
            double outcome = withdrawing(account_number, amount);
            if (outcome<0) {
                deposite(account_number, amount);
                printf("Cannot withdraw more than the balance\n");
                printf("\n");
                break;
            }
            printf("The new balance is: %0.2lf\n", outcome);
            printf("\n");
            break;  
        case 'C':
            printf("Please enter account number: ");
            if(scanf("%d", &account_number)!=1){
                printf("Failed to read the account number\n");
                printf("\n");
                break;
            }
            if (account_number < 901 || account_number > 950)
            {
                printf("Invalid account number\n");
                printf("\n");
                break;
            }
            if (!isOpen(account_number)){
                printf("This account is already closed\n");
                printf("\n");
                break;
            }
            closing(account_number);
            printf("Closed account number %d\n", account_number);
            printf("\n");
            break; 
        case 'I':
            printf("Please enter interest rate: ");
            if(scanf("%lf",&rate)!=1){
                printf("Failed to read the interest rate\n");
                printf("\n");
                break;
            }
            if (rate<0 || rate>100){
                printf("Invalid interest rate\n");
                printf("\n");
                break;
            }
            insert_rate(rate);
            printf("\n");
            printf("\n");
            break;
        case 'P': 
            printing();
            printf("\n");
            break;
        default:
            if(ch!='E'){
                printf("Invalid transaction type\n");
                printf("\n");
                break;
            }
            break;
        } 
    }
    Exit();
    return 0;
}