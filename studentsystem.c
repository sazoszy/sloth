#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int IDs[100];
int count = 0;
char names[100][50];
float grades[100];

void addStudents();
void viewStudents();
void searchStudents();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while(1) {
        printf("Student Lounge\n1. Add Student\n2. View Student List\n3. Search Student Name\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudents(); break;
            case 2: viewStudents(); break;
            case 3: searchStudents(); break;
            case 4: exit(0); break;
            default: 
                printf("\nInvalid Choice.\n"); 
                break;
        }
        system("cls");
    }
}

void addStudents() {
    FILE *cs = fopen("envy.txt", "a");
    if (!cs) {
        printf("File Not Found.\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &IDs[count]);

    printf("Enter student name: ");
    getchar();
    fgets(names[count], sizeof(names[count]), stdin);
    names[count][strcspn(names[count], "\n")] = '\0';

    printf("Enter Grade: ");
    scanf("%f", &grades[count]);

    fprintf(cs, "%d,%s,%.2f\n", IDs[count], names[count], grades[count]);
    fclose(cs);

    count++;
    printf("\nStudent Added Successfully.\n");
}

void viewStudents() {
    FILE *cs = fopen("envy.txt", "r");
    if (!cs) {
        printf("No Record Found.\n");
        return;
    }

    int id;
    char name[50];
    float grade;

    printf("\nStudent List\n");
    while (fscanf(cs, "%d,%49[^,],%f\n", &id, name, &grade) == 3) {
        printf("ID: %d | Name: %s | Grade: %.2f\n", id, name, grade);
    }
    fclose(cs);

    printf("\nPress any button to continue");
    getchar(); getchar(); 
    system("cls"); 
}

void searchStudents() {
    FILE *cs = fopen("envy.txt", "r");
    if (!cs) {
        printf("No Record Found.\n");
        return;
    }

    char searchName[50], name[50];
    int id, found = 0;
    float grade;

    printf("\nEnter student name to search: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fscanf(cs, "%d,%49[^,],%f\n", &id, name, &grade) == 3) {
        if (strcmp(name, searchName) == 0) {
            printf("\nRecord Found.\n");
            printf("ID: %d | Name: %s | Grade: %.2f\n", id, name, grade);
            found  = 1;
            break;
        }
    }

    if (!found) {
        printf("\nRecord Not Found.\n");
    }

    fclose(cs);
    printf("\nPress any button to continue");
    getchar(); 
    system("cls"); 
}
