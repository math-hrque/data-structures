#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct FibNode {
    int key;
    int degree;
    struct FibNode *parent, *child, *left, *right;
    int mark;
} FibNode;

typedef struct FibHeap {
    FibNode* min;
    int n;
} FibHeap;

FibHeap* createFibHeap() {
    FibHeap* heap = (FibHeap*)malloc(sizeof(FibHeap));
    heap->min = NULL;
    heap->n = 0;
    return heap;
}

FibNode* createFibNode(int key) {
    FibNode* node = (FibNode*)malloc(sizeof(FibNode));
    node->key = key;
    node->degree = 0;
    node->parent = node->child = NULL;
    node->left = node->right = node;
    node->mark = 0;
    return node;
}

void insertFibHeap(FibHeap* heap, FibNode* node) {
    if (!heap->min) {
        heap->min = node;
    } else {
        node->left = heap->min;
        node->right = heap->min->right;
        heap->min->right = node;
        node->right->left = node;
        if (node->key < heap->min->key) {
            heap->min = node;
        }
    }
    heap->n++;
}

FibNode* extractMinFibHeap(FibHeap* heap) {
    FibNode* minNode = heap->min;
    if (minNode) {

        FibNode* child = minNode->child;
        if (child) {
            do {
                FibNode* nextChild = child->right;
                child->left = heap->min;
                child->right = heap->min->right;
                heap->min->right = child;
                child->right->left = child;
                child->parent = NULL;
                child = nextChild;
            } while (child != minNode->child);
        }

        minNode->left->right = minNode->right;
        minNode->right->left = minNode->left;

        if (minNode == minNode->right) {
            heap->min = NULL;
        } else {
            heap->min = minNode->right;
        }
        heap->n--;
    }
    return minNode;
}

int main() {
    FibHeap* heap = createFibHeap();

    FibNode* n1 = createFibNode(10);
    FibNode* n2 = createFibNode(20);
    FibNode* n3 = createFibNode(5);

    insertFibHeap(heap, n1);
    insertFibHeap(heap, n2);
    insertFibHeap(heap, n3);

    printf("Min key: %d\n", heap->min->key);

    FibNode* min = extractMinFibHeap(heap);
    printf("Extracted Min: %d\n", min->key);

    free(min);
    free(heap);

    return 0;
}
