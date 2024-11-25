#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int numVertices;
    int** adjMatrix;
} Graph;

Graph* createMatrixGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    return graph;
}

void addMatrixEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}

void printMatrixGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrixGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int vertices = 4;
    Graph* graph = createMatrixGraph(vertices);

    addMatrixEdge(graph, 0, 1, 1);
    addMatrixEdge(graph, 1, 2, 1);
    addMatrixEdge(graph, 2, 3, 1);
    addMatrixEdge(graph, 3, 0, 1);

    printMatrixGraph(graph);
    freeMatrixGraph(graph);

    return 0;
}
