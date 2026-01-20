#include <stdio.h>
#include <stdlib.h>

int main() {

    int w, x;
    int code;

        startUp:
        printf("Menu\n1. Generate Student ID Number\n2. Generate Faculty Member ID\n3. Exit\nChoice: ");
        scanf("%d", &w);

            switch (1) {
                case 1: {
                    int y = 1;
                    printf("Enter Amount of Student ID Number to Generate: ");
                    scanf("%d", &code);

                    while (y <= code) {
                        printf("20250%d-S\n", y);
                        y++;
                    } goto endPoint;
                }
                
                case 2: {
                    printf("Enter Amount of Faculty Member ID to Generate: ");
                    scanf("%d", &code);

                    for (int z = 1 ; z <= code; z++) {
                    printf("20250%d-F\n", z);
                    }
                } goto endPoint;
                
                case 3: 
                    printf("Program Executed. Thank you for Choosing UCC.\n");
                    break;

                    default:
                    system("cls"); printf("Invalid Choice. Please try again.\n"); goto startUp; 
            }

endPoint:
printf("Do You Wish to Re-choose Another Program\n1. Yes\n2. No\nChoice: ");
scanf("%d", &x);

if (x == 1) {
    system("cls"); goto startUp;
} else if (x == 2) {
    system("cls"); printf("Thank you for Choosing UCC.\n");
} else {
    system("cls"); printf("Invalid Input. Choose only option 1 or 2.\n"); goto endPoint;
}

    return 0;
}

