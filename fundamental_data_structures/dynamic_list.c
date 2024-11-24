#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray {
    int *data;
    int start, end, size;
} DynamicArray;

void initialize_array(DynamicArray *array);
int insert_into_array(DynamicArray *array, int value);
int find_in_array(DynamicArray array, int value, int *index);
void list_array(DynamicArray array);
int delete_from_array(DynamicArray *array, int index);
int array_size(DynamicArray array);

int main() {
    int option = 1;
    int value, position = 0;
    int *index = &position;
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(sizeof(int) * array->size);

    initialize_array(array);

    insert_into_array(array, 10);
    insert_into_array(array, 20);
    insert_into_array(array, 30);
    insert_into_array(array, 40);
    insert_into_array(array, 50);
    insert_into_array(array, 60);

    list_array(*array);

    delete_from_array(array, 5);
    insert_into_array(array, 80);
    list_array(*array);

    printf("Enter a value to modify the first element:\nValue: ");
    scanf("%d", &value);
    array->data[0] = value;
    list_array(*array);

    printf("Enter the value you want to find in the array -> ");
    scanf("%d", &value);

    if (find_in_array(*array, value, index)) {
        printf("The value %d is at position [%d] in the array.\n", value, position);
    } else {
        printf("Value %d does not exist in this array!\n", value);
    }

    return 0;
}

void initialize_array(DynamicArray *array) {
    array->start = 0;
    array->end = 0;
}

int insert_into_array(DynamicArray *array, int value) {
    if (array->end < array->size) {
        array->data[array->end] = value;
        (array->end)++;
        return 1;
    }
    return 0;
}

int find_in_array(DynamicArray array, int value, int *index) {
    int i, found = 0;

    for (i = 0; i < array.end; i++) {
        if (array.data[i] == value) {
            *index = i;
            found = 1;
        }
    }
    return found;
}

int delete_from_array(DynamicArray *array, int index) {
    int i;

    if ((index >= 0) && (index < array->end)) {
        for (i = index; i < array->end - 1; i++) {
            array->data[i] = array->data[i + 1];
        }
        (array->end)--;
        return 1;
    }
    return 0;
}

int array_size(DynamicArray array) {
    return array.end;
}

void list_array(DynamicArray array) {
    int i;

    printf("Array Values:\n");

    for (i = array.start; i < array.end; ++i) {
        printf("[%d]%d\n", i, array.data[i]);
    }
    printf("\n\n");
}
