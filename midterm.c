#include <stdio.h>
#include <stdlib.h>

int main() {

    int option, enteredUserID, enteredPassCode, specs, compo, confirm;
    int userID = 0, passCode = 0, registered = 0;

        while (1) {

            entry:
            printf("\nAccount Login\n1. Login\n2. Register\n3. Exit\n\nChoose an option: ");
            scanf("%d", &option);

                if(option == 2) {
                    printf("\nEnter Account User ID: ");
                    scanf("%d", &userID);
                    printf("Enter Passcode: ");
                    scanf("%d", &passCode);
                    printf("Confirm Passcode: ");
                    scanf("%d", &confirm);

                        if (confirm != passCode) {
                            system("cls"); printf("\nPasscode did not match. Please try again.\n");
                        } else {
                            system("cls"); printf("\nAccount Registered. Re-enter you registered account below:\n");
                            registered = 1;

                                for(compo = 3; compo > 0; compo--) {
                                    printf("\nEnter Registered Account: ");
                                    scanf("%d", &enteredUserID);
                                    printf("Enter Passcode: ");
                                    scanf("%d", &enteredPassCode);

                                        if (enteredUserID == userID && enteredPassCode == passCode) {
                                            system("cls"); printf("\nSuccessfully Logged in.\n");
                                            break;
                                        } else {
                                            system("cls"); printf("\nInvalid entered credentials. Attempts left: %d\n", compo - 1);
                                        }
                                } if (compo == 0) {
                                    system("cls"); printf("\nAttempt ran out. \nProgram Terminated.\n"); return 0;
                                }
                        }
                } else if (option == 1) {
                    if (registered == 0) {
                        system("cls"); printf("\nNo account found. Register an Account first.\n");
                    } else {
                        for(compo = 3; compo > 0; compo--) {
                                    printf("\nEnter Registered Account: ");
                                    scanf("%d", &enteredUserID);
                                    printf("Enter Passcode: ");
                                    scanf("%d", &enteredPassCode);

                                        if (enteredUserID == userID && enteredPassCode == passCode) {
                                            system("cls"); printf("\nWelcome, User %d\n", enteredUserID); goto specified;
                                            break;
                                        } else {
                                            system("cls"); printf("Invalid entered credentials. Attempts left: %d\n", compo - 1);
                                        }
                                } if (compo == 0) {
                                    system("cls"); printf("\nAttempt ran out. \nProgram Terminated.\n"); return 0;
                                }
                    }
                } else if (option == 3) {
                    theory:
                    system("cls"); printf("\nProgram Terminated. Thank you.\n"); return 0;
                } else {
                    system("cls"); printf("\nInvalid Choice. Try again.\n"); goto entry;
                }

            specified:
                printf("\nDo you like to jump to start?\n1. Yes\n2. No\nChoice: ");
                scanf("%d", &specs);
                    if (specs == 2) {
                        system("cls"); goto theory;
                    } else if (specs == 1) {
                        system("cls"); goto entry;
                    } else {
                        system("cls"); printf("Invalid option. Try again."); goto entry;
                    }
        }
    return 0;
}
