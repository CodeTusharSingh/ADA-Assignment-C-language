#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
struct Node {
    char data;
    unsigned frequency;
    struct Node *left, *right;
};

// Priority queue structure
struct PriorityQueue {
    unsigned size;
    unsigned capacity;
    struct Node** array;
};

// Create a new node
struct Node* createNode(char data, unsigned frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Create a priority queue
struct PriorityQueue* createPriorityQueue(unsigned capacity) {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Swap two nodes
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a priority queue
void heapify(struct PriorityQueue* queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->array[left]->frequency < queue->array[smallest]->frequency)
        smallest = left;

    if (right < queue->size && queue->array[right]->frequency < queue->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapNodes(&queue->array[smallest], &queue->array[index]);
        heapify(queue, smallest);
    }
}

// Check if the priority queue has only one node
int isSizeOne(struct PriorityQueue* queue) {
    return queue->size == 1;
}

// Check if a node is a leaf node
int isLeaf(struct Node* node) {
    return !(node->left) && !(node->right);
}

// Extract the node with the minimum frequency from the priority queue
struct Node* extractMin(struct PriorityQueue* queue) {
    struct Node* temp = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    heapify(queue, 0);
    return temp;
}

// Insert a node into the priority queue
void insertNode(struct PriorityQueue* queue, struct Node* node) {
    ++queue->size;
    int i = queue->size - 1;
    while (i && node->frequency < queue->array[(i - 1) / 2]->frequency) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}

// Build the Huffman tree
struct Node* buildHuffmanTree(char data[], unsigned frequency[], int size) {
    struct Node *left, *right, *top;
    struct PriorityQueue* queue = createPriorityQueue(size);
    for (int i = 0; i < size; ++i)
        insertNode(queue, createNode(data[i], frequency[i]));

    while (!isSizeOne(queue)) {
        left = extractMin(queue);
        right = extractMin(queue);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertNode(queue, top);
    }

    return extractMin(queue);
}

// Print Huffman codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman coding function
void huffmanCoding(char data[], unsigned frequency[], int size) {
    struct Node* root = buildHuffmanTree(data, frequency, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    huffmanCoding(data, frequency, size);
    return 0;
}
