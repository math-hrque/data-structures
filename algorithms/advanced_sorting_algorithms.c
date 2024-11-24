#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mergeSort(char arr[], int l, int r);
void quickSort(char arr[], int low, int high);
void heapSort(char arr[], int n);
void radixSort(char arr[], int n);
void merge(char arr[], int l, int m, int r);
int partition(char arr[], int low, int high);
void heapify(char arr[], int n, int i);
void countingSortForRadix(char arr[], int n, int exp);

int main() {
    char name[100];
    int i;

    printf("Enter your full name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nYour name before sorting: %s\n", name);

    int size = strlen(name);

    clock_t start, end;
    double merge_sort_time = 0.0;
    double quick_sort_time = 0.0;
    double heap_sort_time = 0.0;
    double radix_sort_time = 0.0;

    start = clock();
    for (i = 0; i < 100000; i++) {
        char temp[size + 1];
        strcpy(temp, name);
        mergeSort(temp, 0, size - 1);
    }
    end = clock();
    merge_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n-----------------------Merge Sort-----------------------\n");
    char temp[size + 1];
    strcpy(temp, name);
    mergeSort(temp, 0, size - 1);
    printf("Sorted with Merge Sort (ascending order): %s\n", temp);
    printf("Merge Sort execution time: %.6lf seconds\n", merge_sort_time);

    start = clock();
    for (i = 0; i < 100000; i++) {
        char temp[size + 1];
        strcpy(temp, name);
        quickSort(temp, 0, size - 1);
    }
    end = clock();
    quick_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n-----------------------Quick Sort-----------------------\n");
    strcpy(temp, name);
    quickSort(temp, 0, size - 1);
    printf("Sorted with Quick Sort (ascending order): %s\n", temp);
    printf("Quick Sort execution time: %.6lf seconds\n", quick_sort_time);

    start = clock();
    for (i = 0; i < 100000; i++) {
        char temp[size + 1];
        strcpy(temp, name);
        heapSort(temp, size);
    }
    end = clock();
    heap_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n-----------------------Heap Sort-----------------------\n");
    strcpy(temp, name);
    heapSort(temp, size);
    printf("Sorted with Heap Sort (ascending order): %s\n", temp);
    printf("Heap Sort execution time: %.6lf seconds\n", heap_sort_time);

    start = clock();
    for (i = 0; i < 100000; i++) {
        char temp[size + 1];
        strcpy(temp, name);
        radixSort(temp, size);
    }
    end = clock();
    radix_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n-----------------------Radix Sort-----------------------\n");
    strcpy(temp, name);
    radixSort(temp, size);
    printf("Sorted with Radix Sort (ascending order): %s\n", temp);
    printf("Radix Sort execution time: %.6lf seconds\n", radix_sort_time);

    return 0;
}

void mergeSort(char arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(char arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    char *L = (char *)malloc(n1 * sizeof(char));
    char *R = (char *)malloc(n2 * sizeof(char));

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void heapSort(char arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        char temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void heapify(char arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        char temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void radixSort(char arr[], int n) {
    int max = 255;  // Maximum ASCII value
    countingSortForRadix(arr, n, max);
}

void countingSortForRadix(char arr[], int n, int range) {
    int count[256] = {0};
    char output[n];

    for (int i = 0; i < n; i++)
        count[(int)arr[i]]++;

    for (int i = 1; i < 256; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(int)arr[i]] - 1] = arr[i];
        count[(int)arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
