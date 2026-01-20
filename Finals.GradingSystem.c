/* "Grading System" code: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 3
#define MAX_SUBJECTS 3
#define MAX_CLASSES 2   


void enterGrades();
void viewGrades();
char getLetterGrade(float avg);
void menu();

float grades[MAX_CLASSES][MAX_STUDENTS][MAX_SUBJECTS];
char names[MAX_CLASSES][MAX_STUDENTS][50];
int studentCount[MAX_CLASSES] = {0};

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n==== Grading System ====\n");
        printf("1. Enter Grades\n");
        printf("2. View Grades\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enterGrades(); break;
            case 2: viewGrades(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void enterGrades() {
    int cls, i, j;
    FILE *fp = fopen("grades.txt", "a");

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter class number (0 to %d): ", MAX_CLASSES-1);
    scanf("%d", &cls);

    if (cls < 0 || cls >= MAX_CLASSES) {
        printf("Invalid class!\n");
        return;
    }

    int count = studentCount[cls];
    if (count >= MAX_STUDENTS) {
        printf("Class is full!\n");
        return;
    }

    printf("Enter student name: ");
    getchar();
    fgets(names[cls][count], 50, stdin);
    names[cls][count][strcspn(names[cls][count], "\n")] = '\0';

    for (j = 0; j < MAX_SUBJECTS; j++) {
        printf("Enter grade for Subject %d: ", j+1);
        scanf("%f", &grades[cls][count][j]);
    }

    // Save to file
    fprintf(fp, "Class %d, %s", cls, names[cls][count]);
    for (j = 0; j < MAX_SUBJECTS; j++) {
        fprintf(fp, ", %.2f", grades[cls][count][j]);
    }
    fprintf(fp, "\n");

    fclose(fp);

    studentCount[cls]++;
    printf("Grades entered successfully!\n");
}

void viewGrades() {
    int cls, i, j;
    float sum, avg;
    char remark[10];

    printf("Enter class number (0 to %d): ", MAX_CLASSES-1);
    scanf("%d", &cls);

    if (cls < 0 || cls >= MAX_CLASSES) {
        printf("Invalid class!\n");
        return;
    }

    if (studentCount[cls] == 0) {
        printf("No students in this class.\n");
        return;
    }

    printf("\n--- Grades for Class %d ---\n", cls);
    for (i = 0; i < studentCount[cls]; i++) {
        sum = 0;
        for (j = 0; j < MAX_SUBJECTS; j++) {
            sum += grades[cls][i][j];
        }
        avg = sum / MAX_SUBJECTS;

        if (avg >= 75) strcpy(remark, "Pass");
        else strcpy(remark, "Fail");

        printf("Student: %s | Average: %.2f | Grade: %c | Remark: %s\n",
               names[cls][i], avg, getLetterGrade(avg), remark);
    }
}

char getLetterGrade(float avg) {
    switch ((int)avg / 10) {
        case 10:
        case 9: return 'A';
        case 8: return 'B';
        case 7: return 'C';
        case 6: return 'D';
        default: return 'F';
    }
}

