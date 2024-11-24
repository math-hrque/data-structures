#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void insertionSort(char arr[], int n);
int binarySearch(char arr[], int start, int end, char letter);

int main() {
    char name[100];
    char search_letter;
    int i;

    printf("Enter your full name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nYour name before sorting: %s\n", name);

    int size = strlen(name);

    clock_t start_time, end_time;
    double insertion_sort_time = 0.0;

    start_time = clock();
    for (i = 0; i < 100000; i++) {
        insertionSort(name, size);
    }
    end_time = clock();
    insertion_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n---------------------Insertion Sort---------------------\n");
    printf("Sorted with Insertion Sort (ascending order): %s\n", name);
    printf("Insertion Sort execution time: %.6lf seconds\n", insertion_sort_time);

    printf("\n---------------------Binary Search---------------------\n");
    printf("Enter a letter to search: ");
    scanf(" %c", &search_letter);

    int position = binarySearch(name, 0, size - 1, search_letter);

    if (position != -1) {
        printf("-> The letter '%c' was found at position: %i.\n", search_letter, position);
    } else {
        printf("-1 (Letter not found)\n");
    }

    printf("\n");

    return 0;
}

void insertionSort(char arr[], int n) {
    int i, j;
    char temp;

    for (j = 1; j < n; j++) {
        temp = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > temp) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = temp;
    }
}

int binarySearch(char arr[], int start, int end, char letter) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == letter) {
        return mid;
    } else if (arr[mid] < letter) {
        return binarySearch(arr, mid + 1, end, letter);
    } else {
        return binarySearch(arr, start, mid - 1, letter);
    }
}
