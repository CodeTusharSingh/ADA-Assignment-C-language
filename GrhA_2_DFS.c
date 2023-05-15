#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Graph representation using adjacency list
struct Graph {
    int numNodes;
    int** adjList;
};

// Create graph
struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    graph->adjList = (int**)malloc(numNodes * sizeof(int*));
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    graph->adjList[src] = (int*)realloc(graph->adjList[src], (2 * sizeof(int)));
    graph->adjList[src][0]++;  // Increment the number of adjacent nodes
    graph->adjList[src][graph->adjList[src][0]] = dest;

    // Add edge from dest to src (assuming undirected graph)
    graph->adjList[dest] = (int*)realloc(graph->adjList[dest], (2 * sizeof(int)));
    graph->adjList[dest][0]++;  // Increment the number of adjacent nodes
    graph->adjList[dest][graph->adjList[dest][0]] = src;
}

// Depth First Search (DFS) algorithm
void DFS(struct Graph* graph, int node, int* visited) {
    visited[node] = 1;  // Mark the current node as visited
    printf("%d ", node);

    // Traverse the adjacent nodes
    for (int i = 1; i <= graph->adjList[node][0]; i++) {
        int adjacentNode = graph->adjList[node][i];
        if (!visited[adjacentNode]) {
            DFS(graph, adjacentNode, visited);
        }
    }
}

// Traverse the graph and find connected components
void findConnectedComponents(struct Graph* graph) {
    int* visited = (int*)calloc(graph->numNodes, sizeof(int));

    printf("Connected Components:\n");
    for (int node = 0; node < graph->numNodes; node++) {
        if (!visited[node]) {
            DFS(graph, node, visited);
            printf("\n");
        }
    }

    free(visited);
}

int main() {
    int numNodes = 7;
    struct Graph* graph = createGraph(numNodes);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    findConnectedComponents(graph);

    return 0;
}
