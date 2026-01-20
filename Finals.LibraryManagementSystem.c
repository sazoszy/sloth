/* "Library Management System" code: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int available;
};

void addBook();
void viewBooks();
void borrowBook();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n==== Library System ====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Borrow Book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: borrowBook(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void addBook() {
    FILE *fp = fopen("library.txt", "a");
    struct Book b;

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter book title: ");
    getchar();
    fgets(b.title, 50, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter author: ");
    fgets(b.author, 50, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    b.available = 1;
    fprintf(fp, "%s,%s,%d\n", b.title, b.author, b.available);
    fclose(fp);
    printf("Book added!\n");
}

void viewBooks() {
    FILE *fp = fopen("library.txt", "r");
    struct Book b;

    if (!fp) {
        printf("No books found.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    while (fscanf(fp, "%49[^,],%49[^,],%d\n", b.title, b.author, &b.available) == 3) {
        printf("Title: %s | Author: %s | Status: %s\n", b.title, b.author, b.available ? "Available" : "Borrowed");
    }
    fclose(fp);
}

void borrowBook() {
    FILE *fp = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Book b;
    char search[50];
    int found = 0;

    if (!fp || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter title to borrow: ");
    getchar();
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = '\0';

    while (fscanf(fp, "%49[^,],%49[^,],%d\n", b.title, b.author, &b.available) == 3) {
        if (strcmp(b.title, search) == 0 && b.available == 1) {
            b.available = 0;
            found = 1;
        }
        fprintf(temp, "%s,%s,%d\n", b.title, b.author, b.available);
    }

    fclose(fp);
    fclose(temp);
    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found) printf("Book borrowed!\n");
    else printf("Book not available.\n");
}
