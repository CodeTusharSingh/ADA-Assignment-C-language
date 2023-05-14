#include <stdio.h>

#define MAX_SIZE 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build the table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Print the table K[][]
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            printf("%d ", K[i][w]);
        }
        printf("\n");
    }

    // Return the maximum value that can be obtained
    return K[n][W];
}

int main() {
    int W = 50; // Knapsack capacity
    int weights[] = {10, 20, 30}; // Array of item weights
    int values[] = {60, 100, 120}; // Array of item values
    int n = sizeof(weights) / sizeof(weights[0]); // Number of items

    int maxValue = knapsack(W, weights, values, n);
    printf("Maximum value: %d\n", maxValue);

    return 0;
}
