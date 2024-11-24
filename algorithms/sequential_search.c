#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sequentialSearch(char *array, char target);

int main() {
    char *name = malloc(sizeof(char) * 100);
    char letter;

    printf("Enter your full name (no spaces): ");
    scanf("%s", name);

    printf("\nEnter the letter you want to search for: ");
    scanf(" %c", &letter);

    printf("\n-----------------Sequential Search-----------------");
    sequentialSearch(name, letter);

    printf("\n\n");

    free(name);
    return 0;
}

void sequentialSearch(char *array, char target) {
    int position = -1;

    for (int i = 0; i < strlen(array); i++) {
        if (array[i] == target) {
            position = i;
            printf("\n-> The letter '%c' was found at position: %i.", target, position);
        }
    }
    if (position == -1) {
        printf("\n-1");
    }
}
