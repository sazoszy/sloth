#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int age;
    char name[50];

        file = fopen("students.txt", "w");
            if (file == NULL) {
                printf("File Does Not Exist.\n");
                return 1;
            }

            for (int i = 0; i < 3; i++) {
                printf("Enter Student Name: ", i);
                scanf("%s", name);
                printf("Enter Student Age: ", i);
                scanf("%d", &age);
                system("cls");
                fprintf(file, "%s %d", name, age);
            }

            fclose(file);

            file = fopen("students.txt", "r");
                if (file == NULL) {
                    printf("Error opening file.\n");
                    return 1;
                }

            printf("Students from file:\n");
            printf("--------------------\n");


            while (fscanf(file, "%49s %d", name, &age) == 2) {
                printf("Name: %s, Age: %d\n", name, age);
            }

fclose(file);

return 0;
}

