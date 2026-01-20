#include <stdio.h>


int main() {

int userID;
int passCode;

    freshstart:
    printf("Enter User ID: ");
    scanf("%d", &userID);

    if (userID == 2114) {
        goto passWord;
    } else {
        printf("User ID is invalid.\n"); goto freshstart;
    }

    passWord:
    printf("Enter Passcode: ");
    scanf("%d", &passCode);

    if (passCode == 123) {
        printf("Access Granted. Please proceed.\n");
    } else {
        printf("Wrong Passcode. Please try again.\n"); goto passWord;
    }



return 0;
}
