#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int data;
  struct tree *left;
  struct tree *right;
} Tree;

int search(Tree *t, int value) {
  if (t == NULL) {
    return 0;
  } else if (value < t->data) {
    return search(t->left, value);
  } else if (value > t->data) {
    return search(t->right, value);
  } else {
    return 1;
  }
}

Tree* insert(Tree *t, int value) {
  if (t == NULL) {
    t = (Tree*)malloc(sizeof(Tree));
    t->data = value;
    t->left = t->right = NULL;
  } else if (value < t->data) {
    t->left = insert(t->left, value);
  } else {
    t->right = insert(t->right, value);
  }
  return t;
}

void inOrder(Tree *t) {
  if (!t)
    return;
  inOrder(t->left);
  printf("%d ", t->data);
  inOrder(t->right);
}

Tree* removeNode(Tree *t, int value) {
  Tree *aux, *parent_aux;
  int children = 0, temp;

  if (!t)
    return NULL;

  if (t->data < value) {
    t->right = removeNode(t->right, value);
  } else if (t->data > value) {
    t->left = removeNode(t->left, value);
  } else {
    if (t->left)
      children++;
    if (t->right)
      children++;

    if (children == 0) {
      free(t);
      return NULL;
    } else if (children == 1) {
      aux = t->left ? t->left : t->right;
      free(t);
      return aux;
    } else {
      aux = t->left;
      parent_aux = t;
      while (aux->right) {
        parent_aux = aux;
        aux = aux->right;
      }
      temp = t->data;
      t->data = aux->data;
      aux->data = temp;
      parent_aux->right = removeNode(aux, temp);
      return t;
    }
  }

  return t;
}

void printTree(Tree *t, int spaces) {
  int i;
  for (i = 0; i < spaces; i++) printf(" ");
  if (!t) {
    printf("//\n");
    return;
  }

  printf("%d\n", t->data);
  printTree(t->left, spaces + 2);
  printTree(t->right, spaces + 2);
}

int main() {
  Tree *t;

  t = insert(NULL, 50);
  t = insert(t, 30);
  t = insert(t, 90);
  t = insert(t, 20);
  t = insert(t, 40);
  t = insert(t, 95);
  t = insert(t, 10);
  t = insert(t, 35);
  t = insert(t, 45);
  t = insert(t, 37);

  printf("\nInitial tree:\n");
  printTree(t, 0);
  printf("\n");

  printf("Removing nodes: 45, 50, 90\n");
  t = removeNode(t, 45);
  t = removeNode(t, 50);
  t = removeNode(t, 90);

  printf("\nTree after removing 45, 50, and 90:\n");
  printTree(t, 0);
  printf("\n");

  return 0;
}
