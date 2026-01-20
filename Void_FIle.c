#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tasks[50][100]; 
int taskCount = 0;

void loadTasks();
void saveTasks();
void addTask();
void viewTasks();
void deleteTask();
void showMenu();

int main() {
    int choice;

    loadTasks();

    while (1) {
        system("cls");
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                system("cls");
                printf("\nSaved. Thank you.\n");
                saveTasks();
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
                printf("\nPress any key to return.\n");
                getchar();
        }
    }
}

void showMenu() {
    printf("==== TO-DO LIST MANAGER ====\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Save & Exit\n");
}

void loadTasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        return; 
    }

    while (fgets(tasks[taskCount], sizeof(tasks[taskCount]), file)) {
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0'; 
        taskCount++;
        if (taskCount >= 50) break;
    }

    fclose(file);
}

void saveTasks() {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Error saving tasks.\n");
        return;
    }
        for (int i = 0; i < taskCount; i++) {
            fprintf(file, "%s\n", tasks[i]);
        }

    fclose(file);
}

void addTask() {
    system("cls");
    if (taskCount >= 500) {
        printf("Task list full.\n");
    } else {
        printf("Enter a new task: ");
        fgets(tasks[taskCount], sizeof(tasks[taskCount]), stdin);
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0';
        taskCount++;
        saveTasks();
        printf("\nTask added successfully.\n");
    }
    printf("\nPress any key to return.\n");
    getchar();
}

void viewTasks() {
    system("cls");
    if (taskCount == 0) {
        printf("No tasks yet.\n");
    } else {
        printf("==== YOUR TASKS ====\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
    printf("\n\nPress any key to return.\n");
    getchar();
}

void deleteTask() {
    system("cls");
    int num;
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
    } else {
        printf("==== DELETE TASK ====\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
        printf("\nEnter task number to delete: ");
        scanf("%d", &num);
        getchar();

        if (num < 1 || num > taskCount) {
            printf("\nInvalid task number.\n");
        } else {
            for (int i = num - 1; i < taskCount - 1; i++) {
                strcpy(tasks[i], tasks[i + 1]);
            }
            taskCount--;
            saveTasks();
            printf("\nTask deleted successfully!\n");
        }
    }
    printf("\nPress any key to return.\n");
    getchar();
}
