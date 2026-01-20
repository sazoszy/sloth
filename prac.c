#include <stdio.h>

int main() {
    int birthYear, age;
    int currentYear = 2025;

    printf("Enter your birthyear:");
    scanf("%d", &birthYear);

    age = currentYear - birthYear;

    if (age >= 18) {
        printf("You are of legal age.\n");
    } else {
        printf("You are underage.\n");
    }

    return 0;
}
