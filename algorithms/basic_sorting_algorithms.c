#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubbleSort(char arr[], int n);
void selectionSort(char arr[], int n);
void insertionSort(char arr[], int n);
void shellSort(char arr[], int n);
void countingSort(char arr[], int n);

int main() {
    char name[100];
    int i;

    printf("Enter your full name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nYour name before sorting: %s\n", name);

    int size = strlen(name);

    clock_t start, end;
    double bubble_sort_time = 0.0;
    double selection_sort_time = 0.0;
    double insertion_sort_time = 0.0;
    double shell_sort_time = 0.0;
    double counting_sort_time = 0.0;

    start = clock();
    for (i = 0; i < 100000; i++) {
        bubbleSort(name, size);
    }
    end = clock();
    bubble_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n-----------------------Bubble Sort-----------------------\n");
    printf("Sorted with Bubble Sort (ascending order): %s\n", name);
    printf("Bubble Sort execution time: %.6lf seconds\n", bubble_sort_time);

    start = clock();
    for (i = 0; i < 100000; i++) {
        selectionSort(name, size);
    }
    end = clock();
    selection_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n---------------------Selection Sort----------------------\n");
    printf("Sorted with Selection Sort (ascending order): %s\n", name);
    printf("Selection Sort execution time: %.6lf seconds\n", selection_sort_time);

    start = clock();
    for (i = 0; i < 100000; i++) {
        insertionSort(name, size);
    }
    end = clock();
    insertion_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n---------------------Insertion Sort---------------------\n");
    printf("Sorted with Insertion Sort (ascending order): %s\n", name);
    printf("Insertion Sort execution time: %.6lf seconds\n", insertion_sort_time);

    start = clock();
    for (i = 0; i < 100000; i++) {
        shellSort(name, size);
    }
    end = clock();
    shell_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n-----------------------Shell Sort-----------------------\n");
    printf("Sorted with Shell Sort (ascending order): %s\n", name);
    printf("Shell Sort execution time: %.6lf seconds\n", shell_sort_time);

    start = clock();
    for (i = 0; i < 100000; i++) {
        countingSort(name, size);
    }
    end = clock();
    counting_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n----------------------Counting Sort----------------------\n");
    printf("Sorted with Counting Sort (ascending order): %s\n", name);
    printf("Counting Sort execution time: %.6lf seconds\n", counting_sort_time);

    return 0;
}

void bubbleSort(char arr[], int n) {
    int i, j;
    char temp;

    for (i = n - 1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(char arr[], int n) {
    int i, j, min;
    char temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
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

void shellSort(char arr[], int n) {
    int i, j, gap;
    char temp;

    for (gap = 1; gap < n; gap = 3 * gap + 1);

    while (gap > 0) {
        gap = (gap - 1) / 3;
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void countingSort(char arr[], int n) {
    int max = 256;
    int count[max];
    char output[n];

    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) {
        count[(int)arr[i]]++;
    }

    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(int)arr[i]] - 1] = arr[i];
        count[(int)arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
