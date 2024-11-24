#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *id;
    int count;
    int size;
} UnionFind;

UnionFind *initUnionFind(int size);
int countComponents(UnionFind *uf);
int areConnected(UnionFind *uf, int p, int q);
int find(UnionFind *uf, int p);
void unionSets(UnionFind *uf, int p, int q);

UnionFind *initUnionFind(int size) {
    int i;
    UnionFind *uf = malloc(sizeof(UnionFind));

    uf->id = malloc(sizeof(int) * size);
    uf->size = size;
    uf->count = size;

    for (i = 0; i < uf->count; ++i) {
        uf->id[i] = i;
    }

    return uf;
}

int countComponents(UnionFind *uf) {
    return uf->count;
}

int areConnected(UnionFind *uf, int p, int q) {
    return find(uf, p) == find(uf, q);
}

int find(UnionFind *uf, int p) {
    while (p != uf->id[p]) {
        uf->id[p] = uf->id[uf->id[p]];
        p = uf->id[p];
    }
    return p;
}

void unionSets(UnionFind *uf, int p, int q) {
    int rootP = find(uf, p);
    int rootQ = find(uf, q);

    if (rootP == rootQ) {
        return;
    }

    uf->id[rootP] = rootQ;
    uf->count--;
}

int main() {
    int size, p, q;
    UnionFind *uf;

    printf("Enter the size of the set (number of elements): ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input. Exiting program.\n");
        return 0;
    }
    uf = initUnionFind(size);

    printf("Enter pairs of elements to connect (enter non-numeric input to stop):\n");

    while (1) {
        if (scanf("%d %d", &p, &q) != 2) {
            printf("Non-numeric input detected. Exiting program.\n");
            break;
        }

        if (!areConnected(uf, p, q)) {
            printf("Connecting %d and %d\n", p, q);
            unionSets(uf, p, q);
        } else {
            printf("%d and %d are already connected.\n", p, q);
        }
    }

    printf("\nTotal connected components: %d\n", countComponents(uf));

    free(uf->id);
    free(uf);

    return 0;
}
