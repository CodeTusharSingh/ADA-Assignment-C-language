#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

// Graph representation using adjacency matrix
struct Graph {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
};

// Function to find the vertex with the minimum key value
int findMinKey(int key[], bool mstSet[], int numNodes) {
    int minKey = INT_MAX;
    int minIndex;

    for (int v = 0; v < numNodes; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the minimum spanning tree
void printMST(int parent[], struct Graph* graph) {
    printf("Minimum Spanning Tree:\n");
    for (int v = 1; v < graph->numNodes; v++) {
        printf("%d - %d\n", parent[v], v);
    }
}

// Prim's algorithm to find the minimum spanning tree
void primMST(struct Graph* graph) {
    int parent[MAX_NODES];     // Array to store the constructed MST
    int key[MAX_NODES];        // Key values used to pick the minimum weight edge
    bool mstSet[MAX_NODES];    // Array to track vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int v = 0; v < graph->numNodes; v++) {
        key[v] = INT_MAX;
        mstSet[v] = false;
    }

    // Start with the first vertex
    key[0] = 0;        // Make the key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;    // First node is always the root of MST

    for (int count = 0; count < graph->numNodes - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = findMinKey(key, mstSet, graph->numNodes);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < graph->numNodes; v++) {
            if (graph->adjMatrix[u][v] && !mstSet[v] && graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    // Print the minimum spanning tree
    printMST(parent, graph);
}

int main() {
    struct Graph graph;
    int numNodes = 5;
    graph.numNodes = numNodes;

    // Initialize adjacency matrix with edge weights
    graph.adjMatrix[0][1] = 2;
    graph.adjMatrix[1][0] = 2;
    graph.adjMatrix[0][3] = 6;
    graph.adjMatrix[3][0] = 6;
    graph.adjMatrix[1][2] = 3;
    graph.adjMatrix[2][1] = 3;
    graph.adjMatrix[1][3] = 8;
    graph.adjMatrix[3][1] = 8;
    graph.adjMatrix[1][4] = 5;
    graph.adjMatrix[4][1] = 5;
    graph.adjMatrix[2][3] = 7;
    graph.adjMatrix[3][2] = 7;
    graph.adjMatrix[2][4] = 9;
    graph.adjMatrix[4][2] = 9;
    graph.adjMatrix[3][4] = 4;
    graph.adjMatrix[4][3] = 4;

    // Find the minimum spanning tree using Prim's algorithm
    primMST(&graph);

    return 0;
}
