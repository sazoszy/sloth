#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char allNames[500] = "";
    char name[50];
    int choice, i;
    
    while (1) {
        system("cls");
        printf("==== NAME STORAGE SYSTEM ====\n1. Add Name\n2. View All Names\n3. Count Characters\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            system("cls");
            printf("\nEnter a name to add: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; 

            if (strlen(allNames) > 0) {
                strcat(allNames, ", ");
            }
            strcat(allNames, name);

            printf("\nName added successfully.\n");
            printf("\nPress any key to return.\n");
            getchar(); 
        } 
        else if (choice == 2) {
            system("cls");
            if (strlen(allNames) == 0) {
                printf("\nNo names stored yet.\n");
            } else {
                printf("\nStored Names: %s\n", allNames);
            }
            printf("\nPress any key to return.\n");
            getchar(); 
        } 
        else if (choice == 3) {
            system("cls");
            int count = 0;
            for (i = 0; allNames[i] != '\0'; i++) {
                count++;
            }
            printf("\nTotal characters stored: %d\n", count);
            printf("\nPress any key to return.\n");
            getchar();
        } 
        else if (choice == 4) {
            printf("\nProgram Terminated.\n");
            break;
        } 
        else {
            printf("\nInvalid choice. Try again.\n");
            printf("\nPress any key to return.\n");
            getchar();
        }
    }
    return 0;
}