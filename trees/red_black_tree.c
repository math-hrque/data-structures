#include <stdio.h>
#include <stdlib.h>

#define RED   1
#define BLACK 0

typedef struct redBlackTree {
  int data;
  int color;
  struct redBlackTree *left;
  struct redBlackTree *right;
} RedBlackTree;

int isRedNode(RedBlackTree *node) {
  if (!node) return BLACK;
  return (node->color == RED);
}

int search(RedBlackTree *tree, int value) {
  if (tree == NULL) return 0;
  else if (value < tree->data) {
    return search(tree->left, value);
  } else if (value > tree->data) {
    return search(tree->right, value);
  } else {
    return 1;
  }
}

void inOrder(RedBlackTree *tree) {
  if (!tree) return;
  inOrder(tree->left);
  printf("%d ", tree->data);
  inOrder(tree->right);
}

void printTree(RedBlackTree *tree, int spaces) {
  int i;
  for (i = 0; i < spaces; i++) printf(" ");
  if (!tree) {
    printf("//\n");
    return;
  }

  printf("%d (%s)\n", tree->data, tree->color == RED ? "RED" : "BLACK");
  printTree(tree->left, spaces + 2);
  printTree(tree->right, spaces + 2);
}

// Left rotation
RedBlackTree* rotateLeft(RedBlackTree *node) {
  RedBlackTree *newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;
  newRoot->color = node->color;
  node->color = RED;
  return newRoot;
}

// Right rotation
RedBlackTree* rotateRight(RedBlackTree *node) {
  RedBlackTree *newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;
  newRoot->color = node->color;
  node->color = RED;
  return newRoot;
}

// Flip colors
void flipColors(RedBlackTree *node) {
  node->color = RED;
  if (node->left) node->left->color = BLACK;
  if (node->right) node->right->color = BLACK;
}

// Insert function for Red-Black Tree
RedBlackTree* insert(RedBlackTree *tree, int value) {
  if (!tree) {
    RedBlackTree *newNode = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    newNode->data = value;
    newNode->color = RED;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  if (value < tree->data) {
    tree->left = insert(tree->left, value);
  } else if (value > tree->data) {
    tree->right = insert(tree->right, value);
  }

  if (isRedNode(tree->right) && !isRedNode(tree->left)) tree = rotateLeft(tree);
  if (isRedNode(tree->left) && isRedNode(tree->left->left)) tree = rotateRight(tree);
  if (isRedNode(tree->left) && isRedNode(tree->right)) flipColors(tree);

  return tree;
}

// Fix root color
RedBlackTree* fixRootColor(RedBlackTree *tree) {
  if (tree) tree->color = BLACK;
  return tree;
}

int main() {
  RedBlackTree *tree = NULL;

  tree = insert(tree, 50);
  tree = insert(tree, 30);
  tree = insert(tree, 70);
  tree = insert(tree, 20);
  tree = insert(tree, 40);
  tree = insert(tree, 60);
  tree = insert(tree, 80);

  tree = fixRootColor(tree);

  printf("\nInitial Red-Black Tree:\n");
  printTree(tree, 0);
  printf("\n");

  printf("In-order Traversal: ");
  inOrder(tree);
  printf("\n");

  int searchValue = 40;
  if (search(tree, searchValue)) {
    printf("\nValue %d found in the Red-Black Tree.\n", searchValue);
  } else {
    printf("\nValue %d not found in the Red-Black Tree.\n", searchValue);
  }

  return 0;
}
