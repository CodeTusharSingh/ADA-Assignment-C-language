#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int matrixChainMultiplication(int dims[], int n) {
    int m[n][n];
    int brackets[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }

    return m[1][n - 1];
}

void printOptimalParenthesis(int brackets[MAX_SIZE][MAX_SIZE], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(brackets, i, brackets[i][j]);
        printOptimalParenthesis(brackets, brackets[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int dims[] = { 10, 30, 5, 60 };
    int n = sizeof(dims) / sizeof(dims[0]);

    int minCost = matrixChainMultiplication(dims, n);

    printf("Minimum cost of matrix chain multiplication: %d\n", minCost);

    int brackets[MAX_SIZE][MAX_SIZE] = { 0 };
    printOptimalParenthesis(brackets, 1, n - 1);
    printf("\n");

    return 0;
}
