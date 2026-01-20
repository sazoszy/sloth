/* "Banking System" code: */

#include <stdio.h>
#include <stdlib.h>

void menu();
void deposit();
void withdraw();
void balanceCheck();

float balance = 1000.0;

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n==== ATM Menu ====\n");
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: deposit(); break;
            case 2: withdraw(); break;
            case 3: balanceCheck(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void deposit() {
    float amount;
    printf("Enter amount: ");
    scanf("%f", &amount);
    balance += amount;
    printf("Deposited %.2f. New balance: %.2f\n", amount, balance);
}

void withdraw() {
    float amount;
    printf("Enter amount: ");
    scanf("%f", &amount);
    if (amount > balance) printf("Insufficient funds!\n");
    else {
        balance -= amount;
        printf("Withdrawn %.2f. New balance: %.2f\n", amount, balance);
    }
}

void balanceCheck() {
    printf("Current Balance: %.2f\n", balance);
}
