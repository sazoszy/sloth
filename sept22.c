#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayStudents() {
    FILE *cs = fopen("students.txt", "r");
    char line[100];

    system("cls");
        if (cs == NULL) {
            printf("\nNo student records found.\n");
            return;
        }

    printf("\n========== Student List ==========\n");
        while (fgets(line, sizeof(line), cs)) {
            printf("%s", line);
        }
    fclose(cs);
}

void addStudent() {
    FILE *cs;
        char name[100];
        char choice = 'y'; 

        while (choice == 'y' || choice == 'Y') {
            cs = fopen("students.txt", "a");
            system("cls");
                if (cs == NULL) {
                    printf("Error opening file.\n");
                    return;
                }

                    printf("Enter student name: ");
                    getchar(); 
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = 0; 

                fprintf(cs, "%s\n", name);
                fclose(cs);
            printf("Student added successfully.\n");
            printf("Would you like to add another student? (y/n): ");
            scanf(" %c", &choice);
        }
}

void editStudent() {
    FILE *cs = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
        char line[100], oldName[100], newName[100];
        int found = 0;
            if (cs == NULL) {
            printf("\nNo student records found.\n");
            return;
            }

                printf("\nEnter the name of the student to edit: ");
                getchar();
                fgets(oldName, sizeof(oldName), stdin);
                oldName[strcspn(oldName, "\n")] = 0;
            printf("\nEnter the new name: ");
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = 0;

    while (fgets(line, sizeof(line), cs)) {
        line[strcspn(line, "\n")] = 0; 
        if (strcmp(line, oldName) == 0) {
            fprintf(temp, "%s\n", newName);
            found = 1;
        } else {
            fprintf(temp, "%s\n", line);
        }
    }

    fclose(cs);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("\nStudent record updated successfully.\n");
    else
        printf("\nStudent name not found.\n");

    printf("\nPress any key to continue.\n");
    getchar();
}

void deleteStudent() {
    FILE *cs = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
        char line[100], delName[100];
        int found = 0;
            if (cs == NULL) {
            printf("\nNo student records found.\n");
            return;
            }

                printf("\nEnter the name of the student to delete: ");
                getchar();
                fgets(delName, sizeof(delName), stdin);
                delName[strcspn(delName, "\n")] = 0;

    while (fgets(line, sizeof(line), cs)) {
        line[strcspn(line, "\n")] = 0; 
        if (strcmp(line, delName) == 0) {
            found = 1;
            continue; 
        }
        fprintf(temp, "%s\n", line);
    }

    fclose(cs);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("\nStudent deleted successfully.\n");
    else
        printf("\nStudent not found.\n");

    printf("\nPress any key to continue.\n");
    getchar();
}

int main() {
    int choice;

    while (1) {
        system("cls");
        printf("\n========== Student File System ==========\n");
        printf("1. View Student List\n");
        printf("2. Add Student Names\n");
        printf("3. Edit Student Name\n");     
        printf("4. Delete Student Name\n");    
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

            switch (choice) {
                case 1:
                    displayStudents();
                    printf("\nPress any key to continue.\n");
                    getchar(); 
                    getchar(); 
                    break;
                case 2:
                    addStudent();
                break;
                case 3:
                    editStudent();
                break;
                case 4:
                    deleteStudent();
                break;
                case 5:
                    printf("Program Executed.\n");
                    return 0;
                default:
                    printf("\nInvalid option. Please try again.\n");
                    printf("\nPress any key to continue.\n");
                    getchar(); 
                    getchar(); 
        }
    }

    return 0;
}
