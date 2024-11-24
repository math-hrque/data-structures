#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack {
    Node* top;
} Stack;

void initializeQueue(Queue* Q);
void initializeStack(Stack* S);
int isQueueEmpty(Queue* Q);
int isStackEmpty(Stack* S);
void enqueue(Queue* Q, int data);
void push(Stack* S, int data);
int dequeue(Queue* Q);
int pop(Stack* S);
void displayQueue(Queue* Q);
void displayStack(Stack* S);
void copyQueueToStack(Queue* Q, Stack* S);

int main() {
    Queue Q;
    Stack S;
    int i, num;

    initializeQueue(&Q);
    initializeStack(&S);

    printf("->ENTER %d NUMBERS TO ADD TO THE QUEUE<-\n\n", MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        printf("Enter number %d for the QUEUE: ", i + 1);
        scanf("%d", &num);
        enqueue(&Q, num);
    }

    printf("\n---------------------BEFORE----------------------\n");

    printf("\nSTACK before copying elements from the QUEUE:\n");
    displayStack(&S);

    printf("\nQUEUE before copying elements to the STACK:\n");
    displayQueue(&Q);

    copyQueueToStack(&Q, &S);

    printf("\n---------------------AFTER---------------------\n");

    printf("\nSTACK after copying elements from the QUEUE:\n");
    displayStack(&S);

    printf("\nQUEUE after copying elements to the STACK:\n");
    displayQueue(&Q);

    printf("\n-----------------------END----------------------\n");

    return 0;
}

void initializeQueue(Queue* Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void initializeStack(Stack* S) {
    S->top = NULL;
}

int isQueueEmpty(Queue* Q) {
    return Q->front == NULL;
}

int isStackEmpty(Stack* S) {
    return S->top == NULL;
}

void enqueue(Queue* Q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(Q)) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

void push(Stack* S, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = S->top;
    S->top = newNode;
}

int dequeue(Queue* Q) {
    if (isQueueEmpty(Q)) {
        printf("The QUEUE is empty!\n");
        return -1;
    }

    Node* frontNode = Q->front;
    int data = frontNode->data;
    Q->front = frontNode->next;

    if (Q->front == NULL) {
        Q->rear = NULL;
    }

    free(frontNode);
    return data;
}

int pop(Stack* S) {
    if (isStackEmpty(S)) {
        printf("The STACK is empty!\n");
        return -1;
    }

    Node* topNode = S->top;
    int data = topNode->data;
    S->top = topNode->next;
    free(topNode);
    return data;
}

void displayQueue(Queue* Q) {
    if (isQueueEmpty(Q)) {
        printf("The QUEUE is empty!\n");
        return;
    }

    Node* currentNode = Q->front;
    printf("QUEUE elements: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void displayStack(Stack* S) {
    if (isStackEmpty(S)) {
        printf("The STACK is empty!\n");
        return;
    }

    Node* currentNode = S->top;
    printf("STACK elements: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void copyQueueToStack(Queue* Q, Stack* S) {
    while (!isQueueEmpty(Q)) {
        int data = dequeue(Q);
        push(S, data);
    }
}
