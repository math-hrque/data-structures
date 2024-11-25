#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

typedef struct Graph {
    int numVertices;
    AdjNode** adjLists;
} Graph;

AdjNode* createNode(int vertex) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->vertex = vertex;
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

void addDirectedEdge(Graph* graph, int src, int dest) {
    AdjNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        AdjNode* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
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
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 4);

    printGraph(graph);
    freeGraph(graph);

    return 0;
}
