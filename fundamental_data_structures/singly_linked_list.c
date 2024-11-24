#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} ListNode;

ListNode *createNode() {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->next = NULL;
    if (!p) {
        printf("Error creating/allocating new node.");
        exit(0);
    }
    return p;
}

void insertAtStart(ListNode *head, int value) {
    ListNode *newNode = createNode();
    newNode->data = value;
    newNode->next = head->next;
    head->next = newNode;
}

void printList(ListNode *listPointer) {
    ListNode *head = listPointer;

    while (listPointer != NULL) {
        if (listPointer != head) {
            printf("%d\n", listPointer->data);
        }
        listPointer = listPointer->next;
    }
    printf("\n");
}

int searchNode(ListNode *head, int value) {
    ListNode *current = head;

    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

ListNode *removeNode(ListNode *head, int value) {
    ListNode *prev = NULL;
    ListNode *current = head;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return 0;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    return head;
}

void insertAtEnd(ListNode **last, int value) {
    ListNode *newNode = createNode();
    ListNode *temp;

    newNode->data = value;
    newNode->next = NULL;

    if (*last == NULL) {
        *last = newNode;
    } else {
        temp = *last;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main(void) {
    ListNode *head = createNode();
    int value;

    for (int i = 0; i < 3; i++) {
        printf("Enter the value for the new node: ");
        scanf("%d", &value);
        insertAtStart(head, value);
    }
    printf("\nInserted values in the list:\n");
    printList(head);

    printf("Enter the value you want to search in the list: ");
    scanf("%d", &value);
    if (searchNode(head, value)) {
        printf("Searched value: %d -> THIS VALUE EXISTS IN THE LIST!\n", value);
    } else {
        printf("Searched value: %d -> THIS VALUE DOES NOT EXIST IN THE LIST!\n", value);
    }

    printf("\nEnter the value you want to remove from the list: ");
    scanf("%d", &value);
    if (removeNode(head, value)) {
        printf("VALUE SUCCESSFULLY REMOVED FROM THE LIST!\n");
    } else {
        printf("THIS VALUE DOES NOT EXIST IN THE LIST!\n");
    }

    printf("\nUpdated list values:\n");
    printList(head);

    printf("Enter a new value to insert at the end of the list: ");
    scanf("%d", &value);
    insertAtEnd(&head, value);

    printf("List values with the new value added at the end:\n");
    printList(head);

    return 0;
}
