#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode *buckets[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *key) {
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = (hashValue * 31 + key[i]) % TABLE_SIZE;
    }
    return hashValue;
}

HashNode *createNode(const char *key, int value) {
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashTable *createTable() {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void insert(HashTable *table, const char *key, int value) {
    unsigned int index = hash(key);
    HashNode *node = table->buckets[index];

    while (node) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }

    HashNode *newNode = createNode(key, value);
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

int search(HashTable *table, const char *key, int *value) {
    unsigned int index = hash(key);
    HashNode *node = table->buckets[index];

    while (node) {
        if (strcmp(node->key, key) == 0) {
            *value = node->value;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void delete(HashTable *table, const char *key) {
    unsigned int index = hash(key);
    HashNode *node = table->buckets[index];
    HashNode *prev = NULL;

    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                table->buckets[index] = node->next;
            }
            free(node->key);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void printTable(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        HashNode *node = table->buckets[i];
        while (node) {
            printf("(%s, %d) -> ", node->key, node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

void freeTable(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *node = table->buckets[i];
        while (node) {
            HashNode *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table);
}

int main() {
    HashTable *table = createTable();

    insert(table, "apple", 5);
    insert(table, "banana", 3);
    insert(table, "orange", 7);
    insert(table, "grape", 4);

    printf("Initial Hash Table:\n");
    printTable(table);

    int value;
    if (search(table, "banana", &value)) {
        printf("\nFound 'banana' with value: %d\n", value);
    } else {
        printf("\n'banana' not found.\n");
    }

    delete(table, "banana");
    printf("\nHash Table after deleting 'banana':\n");
    printTable(table);

    freeTable(table);
    return 0;
}
