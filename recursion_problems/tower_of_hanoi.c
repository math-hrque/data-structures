#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 4

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

typedef struct Game {
    int gameNumber;
    int gameTimeSeconds;
    struct Game* next;
} Game;

void initStack(Stack* s);
int isStackEmpty(Stack* s);
int isStackFull(Stack* s);
void pushStack(Stack* s, int item);
int popStack(Stack* s);
void printStack(Stack s);
void printStackReverse(Stack s);
int getStackSize(Stack* s);

void printBoard();
void initializeBoard();
void startGame(int option);
int isGameFinished();
void performMove(Stack* source, Stack* destination);
void promptMove();
void autoTowerOfHanoi(int n, Stack* source, Stack* destination, Stack* auxiliary);
void startTimer();
double stopTimer();
double getCurrentTime();
Game* initializeGameList();
void addGame(Game** list, int gameNumber, int gameTimeSeconds);
void sortGameList(Game** list);
void printGameList(Game* list);

Stack stackA;
Stack stackB;
Stack stackC;
int moveCount = 0;
int gameCount = 0;
char moveMessage[30] = "";
clock_t timerStart;
double elapsedTime = 0;
Game* gameList;

int main() {
    system("cls");
    int option = 0;
    char message[30] = "";
    gameList = initializeGameList();

    while (option != -1) {
        printf("---- TOWER OF HANOI ----");
        printf("\n%s \n", message);
        printf("\n-- Options:\n");
        printf("-- 1. Create a new board and play (Manual Game - Standard)\n");
        printf("-- 2. Create a new board and play (Manual Game - Randomized)\n");
        printf("-- 3. Test computer intelligence (Automatic Game)\n");
        printf("-- 4. List best times\n");
        printf("-- 5. Exit\n");
        printf("\n-- Choose an option: ");
        scanf("%i", &option);

        switch (option) {
            case 1:
                initializeBoard();
                startGame(1);
                system("cls");
                startTimer();
                strcpy(moveMessage, "Timer started! Good luck!");
                while (!isGameFinished(&stackC)) {
                    printBoard();
                    printf("\nElapsed time -> %.0fs\n", getCurrentTime());
                    promptMove();
                }
                elapsedTime = stopTimer();
                addGame(&gameList, gameCount, elapsedTime);
                strcpy(message, "-> Game finished!");
                moveCount = 0;
                break;
            case 2:
                initializeBoard();
                startGame(0);
                system("cls");
                startTimer();
                strcpy(moveMessage, "Timer started! Good luck!");
                while (!isGameFinished(&stackC)) {
                    printBoard();
                    printf("\nElapsed time -> %.0fs\n", getCurrentTime());
                    promptMove();
                }
                elapsedTime = stopTimer();
                addGame(&gameList, gameCount, elapsedTime);
                strcpy(message, "-> Game finished!");
                moveCount = 0;
                break;
            case 3:
                initializeBoard();
                startGame(1);
                system("cls");
                while (!isGameFinished(&stackC)) {
                    autoTowerOfHanoi(MAX_SIZE, &stackA, &stackC, &stackB);
                }
                printf("\n\n---- AUTOMATIC GAME OVER ----\n\n");
                moveCount = 0;
                break;
            case 4:
                printGameList(gameList);
                break;
            case 5:
                exit(0);
            default:
                strcpy(message, "Invalid option!");
                system("cls");
                break;
        }
    }
    return 0;
}

void printBoard() {
    printf("%s", moveMessage);
    printf("\n\n");
    int layer = MAX_SIZE - 1;
    char A = '|', B = '|', C = '|';
    for (int i = 0; i < MAX_SIZE; i++) {
        A = '|';
        B = '|';
        C = '|';
        char temp[4] = "";
        char row[] = " %c \t  %c  \t  %c\n";

        if (!(getStackSize(&stackA) < layer)) {
            sprintf(temp, "%d", *(stackA.items + layer));
            A = temp[0];
        }
        if (!(getStackSize(&stackB) < layer)) {
            sprintf(temp, "%d", *(stackB.items + layer));
            B = temp[0];
        }
        if (!(getStackSize(&stackC) < layer)) {
            sprintf(temp, "%d", *(stackC.items + layer));
            C = temp[0];
        }

        printf(row, A, B, C);
        layer--;
    }
    printf(" _ \t  _ \t  _ \t\n");
    printf(" A \t  B \t  C \t\n");
}

void initializeBoard() {
    initStack(&stackA);
    initStack(&stackB);
    initStack(&stackC);
}

void startGame(int option) {
    srand(time(NULL));

    if (option) {
        for (int i = MAX_SIZE; !isStackFull(&stackA); i--) {
            pushStack(&stackA, i);
        }
    } else {
        int nums[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++) {
            nums[i] = i + 1;
        }

        for (int i = 0; i < MAX_SIZE; i++) {
            int randomIndex = rand() % (MAX_SIZE - i);
            int num = nums[randomIndex];
            pushStack(&stackA, num);
            nums[randomIndex] = nums[MAX_SIZE - i - 1];
        }
    }
}

void promptMove() {
    int move = 0;
    while (move < 1 || move > 6) {
        printf("\n-> Choose a move: \n");
        printf("\t1. Stack A to Stack B\n");
        printf("\t2. Stack A to Stack C\n");
        printf("\t3. Stack B to Stack A\n");
        printf("\t4. Stack B to Stack C\n");
        printf("\t5. Stack C to Stack A\n");
        printf("\t6. Stack C to Stack B\n");
        printf("\t7. Exit\n");
        printf("Your move: ");
        scanf("%d", &move);

        switch (move) {
            case 1:
                performMove(&stackA, &stackB);
                break;
            case 2:
                performMove(&stackA, &stackC);
                break;
            case 3:
                performMove(&stackB, &stackA);
                break;
            case 4:
                performMove(&stackB, &stackC);
                break;
            case 5:
                performMove(&stackC, &stackA);
                break;
            case 6:
                performMove(&stackC, &stackB);
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid move!\n");
        }
    }
    system("cls");
}

void performMove(Stack* source, Stack* destination) {
    if (!isStackEmpty(source) && (isStackEmpty(destination) || source->items[source->top] < destination->items[destination->top])) {
        int disk = popStack(source);
        pushStack(destination, disk);
        moveCount++;
        strcpy(moveMessage, "");
    } else {
        strcpy(moveMessage, "Invalid move");
    }
}

void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

int isStackFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void pushStack(Stack* s, int item) {
    if (isStackFull(s)) {
        printf("Error: Stack full\n");
        exit(1);
    }
    s->top++;
    s->items[s->top] = item;
}

int popStack(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Error: Stack empty\n");
        exit(1);
    }
    int item = s->items[s->top];
    s->top--;
    return item;
}

int getStackSize(Stack* s) {
    return s->top + 1;
}

int isGameFinished() {
    if (isStackEmpty(&stackA) && isStackFull(&stackC)) {
        gameCount++;
        return 1;
    }
    return 0;
}

void autoTowerOfHanoi(int n, Stack* source, Stack* destination, Stack* auxiliary) {
    if (n == 1) {
        performMove(source, destination);
        printf("\nMove %i:\n", moveCount);
        printBoard();
        return;
    }

    autoTowerOfHanoi(n - 1, source, auxiliary, destination);
    performMove(source, destination);
    printf("\nMove %i:\n", moveCount);
    printBoard();
    autoTowerOfHanoi(n - 1, auxiliary, destination, source);
}

void startTimer() {
    timerStart = clock();
}

double stopTimer() {
    clock_t timerEnd = clock();
    return (double)(timerEnd - timerStart) / CLOCKS_PER_SEC;
}

double getCurrentTime() {
    clock_t currentTime = clock();
    return (double)(currentTime - timerStart) / CLOCKS_PER_SEC;
}

Game* initializeGameList() {
    return NULL;
}

void addGame(Game** list, int gameNumber, int gameTimeSeconds) {
    Game* newGame = (Game*)malloc(sizeof(Game));
    newGame->gameNumber = gameNumber;
    newGame->gameTimeSeconds = gameTimeSeconds;
    newGame->next = NULL;

    if (*list == NULL) {
        *list = newGame;
    } else {
        Game* current = *list;
        Game* previous = NULL;

        while (current != NULL && current->gameTimeSeconds < newGame->gameTimeSeconds) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            newGame->next = *list;
            *list = newGame;
        } else {
            previous->next = newGame;
            newGame->next = current;
        }
    }
}

void sortGameList(Game** list) {
    Game* current = (*list)->next;
    (*list)->next = NULL;
    while (current != NULL) {
        Game* next = current->next;
        Game* previous = NULL;
        Game* iterator = *list;
        while (iterator != NULL && iterator->gameTimeSeconds < current->gameTimeSeconds) {
            previous = iterator;
            iterator = iterator->next;
        }
        if (previous == NULL) {
            current->next = *list;
            *list = current;
        } else {
            previous->next = current;
            current->next = iterator;
        }
        current = next;
    }
}

void printGameList(Game* list) {
    Game* current = list;
    if (current == NULL) {
        printf("\nNo games recorded yet! Play some games to record times.\n\n");
    } else {
        sortGameList(&list);
        printf("\nBest games by time:\n");
        while (current != NULL) {
            printf("\nGame %d: %d seconds", current->gameNumber, current->gameTimeSeconds);
            current = current->next;
        }
        printf("\n===================\n");
    }
}
