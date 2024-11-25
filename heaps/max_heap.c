#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap {
    int* array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->array = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        maxHeapify(heap, largest);
    }
}

void insertMaxHeap(MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow!\n");
        return;
    }

    heap->array[heap->size++] = value;
    int i = heap->size - 1;

    while (i > 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) return -1;

    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    maxHeapify(heap, 0);
    return root;
}

void freeMaxHeap(MaxHeap* heap) {
    free(heap->array);
    free(heap);
}

void printMaxHeap(MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap* heap = createMaxHeap(10);

    insertMaxHeap(heap, 10);
    insertMaxHeap(heap, 20);
    insertMaxHeap(heap, 5);
    insertMaxHeap(heap, 30);

    printf("Max-Heap:\n");
    printMaxHeap(heap);

    printf("Extracted Max: %d\n", extractMax(heap));
    printf("Heap after extraction:\n");
    printMaxHeap(heap);

    freeMaxHeap(heap);
    return 0;
}
