#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

void insert_at_start(Node **list, int num);
void insert_at_end(Node **list, int num);
void insert_at_middle(Node **list, int num, int target);
void insert_sorted(Node **list, int num);
Node *remove_node(Node **list, int num);
Node *search(Node **list, int num);
int calculate_steps(Node **list, int num);
void print_list(Node *node);
Node *get_last(Node **list);
void print_reverse(Node *node);
void remove_duplicates(Node **list);
int calculate_distance(Node **list, int num1, int num2);

int main() {
    int option, value, target, distance;
    Node *removed, *list = NULL;

    do {
        printf("Doubly Linked List:\n");
        printf("0 - Exit\n1 - Insert at start\n2 - Insert at end\n3 - Insert at middle\n4 - Insert sorted\n5 - Remove\n6 - Print\n7 - Calculate distance between nodes\n8 - Print in reverse\n9 - Remove duplicates\n=> ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                insert_at_start(&list, value);
                printf("\n");
                break;

            case 2:
                printf("Enter a value: ");
                scanf("%d", &value);
                insert_at_end(&list, value);
                printf("\n");
                break;

            case 3:
                printf("Enter a value and a target position: ");
                scanf("%d%d", &value, &target);
                insert_at_middle(&list, value, target);
                printf("\n");
                break;

            case 4:
                printf("Enter a value: ");
                scanf("%d", &value);
                insert_sorted(&list, value);
                printf("\n");
                break;

            case 5:
                printf("Enter a value to be removed: ");
                scanf("%d", &value);
                printf("\n");
                removed = remove_node(&list, value);
                if (removed) {
                    printf("Removed element: %d\n\n", removed->value);
                    free(removed);
                } else {
                    printf("Element not found!\n\n");
                }
                break;

            case 6:
                print_list(list);
                break;

            case 7:
                printf("Enter two values to calculate the distance: ");
                scanf("%d%d", &value, &target);
                distance = calculate_distance(&list, value, target);
                printf("\n");
                printf("The distance between %d and %d is %d node(s)\n\n", value, target, distance);
                break;

            case 8:
                print_reverse(get_last(&list));
                printf("\n");
                break;

            case 9:
                remove_duplicates(&list);
                printf("\n");
                break;

            default:
                if (option != 0)
                    printf("Invalid option!\n\n");
        }

    } while (option != 0);
    return 0;
}

void insert_at_start(Node **list, int num) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node) {
        new_node->value = num;
        new_node->next = *list;
        new_node->prev = NULL;
        if (*list)
            (*list)->prev = new_node;
        *list = new_node;
    }
}

void insert_at_end(Node **list, int num) {
    Node *aux, *new_node = malloc(sizeof(Node));
    if (new_node) {
        new_node->value = num;
        new_node->next = NULL;

        if (*list == NULL) {
            *list = new_node;
            new_node->prev = NULL;
        } else {
            aux = *list;
            while (aux->next)
                aux = aux->next;
            aux->next = new_node;
            new_node->prev = aux;
        }
    }
}

void insert_at_middle(Node **list, int num, int target) {
    Node *aux, *new_node = malloc(sizeof(Node));
    if (new_node) {
        new_node->value = num;
        if (*list == NULL) {
            new_node->next = NULL;
            new_node->prev = NULL;
            *list = new_node;
        } else {
            aux = *list;
            while (aux->value != target && aux->next)
                aux = aux->next;
            new_node->next = aux->next;
            if (aux->next)
                aux->next->prev = new_node;
            new_node->prev = aux;
            aux->next = new_node;
        }
    }
}

void insert_sorted(Node **list, int num) {
    Node *aux, *new_node = malloc(sizeof(Node));
    if (new_node) {
        new_node->value = num;
        if (*list == NULL) {
            new_node->next = NULL;
            new_node->prev = NULL;
            *list = new_node;
        } else if (new_node->value < (*list)->value) {
            new_node->next = *list;
            (*list)->prev = new_node;
            *list = new_node;
        } else {
            aux = *list;
            while (aux->next && new_node->value > aux->next->value)
                aux = aux->next;
            new_node->next = aux->next;
            if (aux->next)
                aux->next->prev = new_node;
            new_node->prev = aux;
            aux->next = new_node;
        }
    }
}

Node *remove_node(Node **list, int num) {
    Node *aux = *list, *to_remove = NULL;

    while (aux) {
        if (aux->value == num) {
            to_remove = aux;

            if (aux->prev) {
                aux->prev->next = aux->next;
            } else {
                *list = aux->next;
            }

            if (aux->next) {
                aux->next->prev = aux->prev;
            }

            free(to_remove);
            return NULL;
        }
        aux = aux->next;
    }
    return NULL;
}

Node *search(Node **list, int num) {
    Node *aux = *list;
    while (aux && aux->value != num)
        aux = aux->next;
    return aux;
}

int calculate_steps(Node **list, int num) {
    Node *aux = *list;
    int steps = 0;
    while (aux) {
        if (aux->value == num) {
            return steps;
        }
        aux = aux->next;
        steps++;
    }
    return -1;
}

void print_list(Node *node) {
    printf("\nLIST: ");
    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n\n");
}

Node *get_last(Node **list) {
    if (*list == NULL) {
        return NULL;
    }
    Node *aux = *list;
    while (aux->next) {
        aux = aux->next;
    }
    return aux;
}

void print_reverse(Node *node) {
    if (node == NULL) {
        printf("\nThe list is empty.\n\n");
        return;
    }
    printf("\nREVERSED LIST: ");
    while (node) {
        printf("%d ", node->value);
        node = node->prev;
    }
    printf("\n\n");
}

void remove_duplicates(Node **list) {
    Node *current = *list;
    while (current) {
        Node *compare = current->next;
        while (compare) {
            if (compare->value == current->value) {
                Node *duplicate = compare;
                compare = compare->next;
                remove_node(list, duplicate->value);
            } else {
                compare = compare->next;
            }
        }
        current = current->next;
    }
    printf("---------- LIST AFTER REMOVING DUPLICATES ----------\n");
    print_list(*list);
}

int calculate_distance(Node **list, int num1, int num2) {
    int s1 = calculate_steps(list, num1);
    int s2 = calculate_steps(list, num2);
    int total = abs(s1 - s2);
    return total;
}
