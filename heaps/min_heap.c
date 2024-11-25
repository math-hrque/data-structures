#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap {
    int* array;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
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

void minHeapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMinHeap(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow!\n");
        return;
    }

    heap->array[heap->size++] = value;
    int i = heap->size - 1;

    while (i > 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) return -1;

    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    minHeapify(heap, 0);
    return root;
}

void freeMinHeap(MinHeap* heap) {
    free(heap->array);
    free(heap);
}

void printMinHeap(MinHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    MinHeap* heap = createMinHeap(10);

    insertMinHeap(heap, 10);
    insertMinHeap(heap, 20);
    insertMinHeap(heap, 5);
    insertMinHeap(heap, 30);

    printf("Min-Heap:\n");
    printMinHeap(heap);

    printf("Extracted Min: %d\n", extractMin(heap));
    printf("Heap after extraction:\n");
    printMinHeap(heap);

    freeMinHeap(heap);
    return 0;
}
