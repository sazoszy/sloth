#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inventory[3][3][50]; 
    int branch, category, choice;
    int i, j;
    int count[3][3] = {0};

    while (1) {
        system("cls");
        printf("==== STORE INVENTORY TRACKER ====\n1. Add Item\n2. View All Items\n3. Search for an Item\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            system("cls");
            printf("Select Branch (0-2): ");
            scanf("%d", &branch);
            printf("Select Category (0-2): ");
            scanf("%d", &category);
            getchar();

            if (branch < 0 || branch > 2 || category < 0 || category > 2) {
                printf("\nInvalid branch or category.\n");
            } else if (count[branch][category] >= 1) {
                printf("\nItem slot already filled.\n");
            } else {
                printf("Enter Item Name: ");
                fgets(inventory[branch][category], sizeof(inventory[branch][category]), stdin);
                inventory[branch][category][strcspn(inventory[branch][category], "\n")] = '\0';
                count[branch][category] = 1;
                printf("\nItem added successfully.\n");
            }
            printf("\nPress any key to return.\n");
            getchar();
        } else if (choice == 2) {
            system("cls");
            printf("==== INVENTORY LIST ====\n");
            for (i = 0; i < 3; i++) {
                printf("\n--- Branch %d ---\n", i);
                for (j = 0; j < 3; j++) {
                    if (count[i][j] == 1)
                        printf("Category %d: %s\n", j, inventory[i][j]);
                    else
                        printf("Category %d: [Empty]\n", j);
                }
            }
            printf("\nPress any key to return.\n");
            getchar();
        } else if (choice == 3) {
            system("cls");
            char search[50];
            int found = 0;
            printf("Enter item name to search: ");
            fgets(search, sizeof(search), stdin);
            search[strcspn(search, "\n")] = '\0';

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (count[i][j] == 1 && strcmp(inventory[i][j], search) == 0) {
                        printf("\nItem found in Branch %d, Category %d\n", i, j);
                        found = 1;
                    }
                }
            }
            if (!found)
                printf("\nItem not found.\n");
                printf("\nPress any key to return.\n");
                getchar();
        } else if (choice == 4) {
            system("cls");
            printf("\nProgram Terminated.\n");
            break;
        } else {
            system("cls");
            printf("Invalid choice. Try again.\n");
            printf("\nPress any key to return.\n");
            getchar();
        }
    }
    return 0;
}
