#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 6

typedef struct Array {
    int data[MAX_ARRAY];
    int start, end;
} Array;

void initialize_array(Array *arr);
int insert_into_array(Array *arr, int value);
int find_in_array(Array arr, int value, int *index);
void list_array(Array arr);
int delete_from_array(Array *arr, int index);
int array_size(Array arr);

int main() {
    int option = 1;
    int value, i, search_position = 0;
    int *index = &search_position;
    Array arr;

    initialize_array(&arr);

    insert_into_array(&arr, 10);
    insert_into_array(&arr, 20);
    insert_into_array(&arr, 30);
    insert_into_array(&arr, 40);
    insert_into_array(&arr, 50);
    insert_into_array(&arr, 60);

    list_array(arr);

    delete_from_array(&arr, 5);
    insert_into_array(&arr, 80);
    list_array(arr);

    printf("Enter a value to modify the first element:\nValue -> ");
    scanf("%d", &value);
    arr.data[0] = value;
    list_array(arr);

    printf("Enter the value to search in the array -> ");
    scanf("%d", &value);

    if (find_in_array(arr, value, index)) {
        printf("The value %d is at position [%d] in the array.\n", value, search_position);
    } else {
        printf("Value %d does not exist in this array!\n", value);
    }

    return 0;
}

void initialize_array(Array *arr) {
    arr->start = 0;
    arr->end = 0;
}

int insert_into_array(Array *arr, int value) {
    if (arr->end < MAX_ARRAY) {
        arr->data[arr->end] = value;
        (arr->end)++;
        return 1;
    }
    return 0;
}

int find_in_array(Array arr, int value, int *index) {
    int i, found = 0;

    for (i = 0; i < arr.end; i++) {
        if (arr.data[i] == value) {
            *index = i;
            found = 1;
        }
    }
    return found;
}

int delete_from_array(Array *arr, int index) {
    int i;

    if ((index >= 0) && (index < MAX_ARRAY)) {
        for (i = index; i < arr->end - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        (arr->end)--;
        return 1;
    }
    return 0;
}

int array_size(Array arr) {
    return arr.end;
}

void list_array(Array arr) {
    int i;

    printf("Array Values:\n");

    for (i = arr.start; i < arr.end; ++i) {
        printf("[%d] %d\n", i, arr.data[i]);
    }
    printf("\n");
}
