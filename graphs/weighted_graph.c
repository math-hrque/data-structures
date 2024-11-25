#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
    int vertex;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct Graph {
    int numVertices;
    AdjNode** adjLists;
} Graph;

AdjNode* createNode(int vertex, int weight) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (AdjNode**)malloc(vertices * sizeof(AdjNode*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addWeightedEdge(Graph* graph, int src, int dest, int weight) {
    AdjNode* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        AdjNode* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("(%d, %d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        AdjNode* temp = graph->adjLists[i];
        while (temp) {
            AdjNode* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    int vertices = 4;
    Graph* graph = createGraph(vertices);

    addWeightedEdge(graph, 0, 1, 5);
    addWeightedEdge(graph, 1, 2, 3);
    addWeightedEdge(graph, 2, 3, 2);
    addWeightedEdge(graph, 3, 0, 4);

    printGraph(graph);
    freeGraph(graph);

    return 0;
}
