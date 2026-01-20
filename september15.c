#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *makeFullName(char first[], char last[], char full[]) {
    strcpy(full, first);
    strcat(full, " ");
    strcat(full, last);
    return full;
}

int main() {
    char firstName[50];
    char lastName[50];
    char fullName[100];
    char copiedName[100];
    char search[100];


    printf("Enter your first name: ");
    fgets(firstName, sizeof(firstName), stdin);

    for (int i = 0; firstName[i] != '\0'; i++) {
        if (firstName[i] == '\n') {
            firstName[i] = '\0';
            break;
        }
    }


    printf("Enter your last name: ");
    fgets(lastName, sizeof(lastName), stdin);
    for (int i = 0; lastName[i] != '\0'; i++) {
        if (lastName[i] == '\n') {
            lastName[i] = '\0';
            break;
        }
    }


    makeFullName(firstName, lastName, fullName);


    strcpy(copiedName, fullName);


    printf("\nThe length of your full name is: %lu characters.\n", strlen(fullName));
    printf("Copied name: %s\n\n", copiedName);


    while (1) {
        system("cls"); printf("Enter a name to search: ");
        fgets(search, sizeof(search), stdin);


        for (int i = 0; search[i] != '\0'; i++) {
            if (search[i] == '\n') {
                search[i] = '\0';
                break;
            }
        }


        if (strlen(search) == 0) break;

        if (strcmp(fullName, search) == 0) {
            system("cls"); printf("Match found! The entered name is the same.\n\n");
            break;
        } else {
            system("cls"); printf("No match. The entered name is different.\n\n");
        }
    }

    return 0;
}
