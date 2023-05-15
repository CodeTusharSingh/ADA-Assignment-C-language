#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue implementation for BFS
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Graph representation using adjacency matrix
struct Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
};

// Queue operations
void enqueue(struct Queue* q, int item) {
    q->rear++;
    q->items[q->rear] = item;
}

int dequeue(struct Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

int isEmpty(struct Queue* q) {
    return (q->front > q->rear);
}

// Initialize graph
void initGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;
    int i, j;
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Breadth First Search (BFS) algorithm
void BFS(struct Graph* graph, int startNode, int endNode) {
    int visited[MAX_NODES] = {0};  // Array to track visited nodes
    int predecessor[MAX_NODES] = {-1};  // Array to track predecessors
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;

    visited[startNode] = 1;  // Mark startNode as visited
    enqueue(queue, startNode);  // Enqueue startNode

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        
        // Check if the current node is the end node
        if (currentNode == endNode) {
            printf("Shortest path found!\n");
            printf("Path: ");
            int node = endNode;
            while (node != -1) {
                printf("%d ", node);
                node = predecessor[node];
            }
            printf("\n");
            return;
        }

        // Explore adjacent nodes
        for (int adjacentNode = 0; adjacentNode < graph->numNodes; adjacentNode++) {
            if (graph->adjMatrix[currentNode][adjacentNode] == 1 && !visited[adjacentNode]) {
                visited[adjacentNode] = 1;
                predecessor[adjacentNode] = currentNode;
                enqueue(queue, adjacentNode);
            }
        }
    }

    printf("No path found between the nodes.\n");
}

int main() {
    struct Graph graph;
    int numNodes = 6;
    initGraph(&graph, numNodes);

    // Add edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 5);
    
    int startNode = 0;
    int endNode = 5;

    // Find shortest
    BFS(&graph, startNode, endNode);

    return 0;
}
