#include <stdio.h>

#define MAX_SIZE 100

int lcs(char a[], char b[], int i, int j) {
    int c[MAX_SIZE][MAX_SIZE];

    for (int k = 0; k <= i; k++) {
        for (int l = 0; l <= j; l++) {
            if (k == 0 || l == 0)
                c[k][l] = 0;
        }
    }

    for (int k = 1; k <= i; k++) {
        for (int l = 1; l <= j; l++) {
            if (a[k - 1] == b[l - 1]) {
                c[k][l] = 1 + c[k - 1][l - 1];
            } else if (c[k - 1][l] >= c[k][l - 1]) {
                c[k][l] = c[k - 1][l];
            } else {
                c[k][l] = c[k][l - 1];
            }
        }
    }

    for (int k = 0; k <= i; k++) {
        for (int l = 0; l <= j; l++) {
            printf("%d ", c[k][l]);
        }
        printf("\n");
    }

    return c[i][j];
}

int main() {
    char a[] = {'l', 'o', 'n', 'g', 'e', 's', 't'};
    char b[] = {'s', 't', 'o', 'n', 'e'};
    int i = sizeof(a) / sizeof(a[0]);
    int j = sizeof(b) / sizeof(b[0]);

    int result = lcs(a, b, i, j);
    printf("The length of the longest common subsequence is: %d\n", result);

    return 0;
}
