#include <stdio.h>

#define MAX_SIZE 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int cutTheRod(int p[], int n) {
    int r[n + 1];
    int s[n + 1];

    r[0] = 0;
    int q = -1;
    for (int i = 1; i <= n; i++) {
        q = -1;
        for (int j = 1; j <= i; j++) {
            if (q < p[j] + r[i - j]) {
                q = p[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }

    for (int i = 0; i < n + 1; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    return r[n];
}

int main() {
    int p[] = { 0, 1, 5, 8, 10, 13, 17, 18, 22, 25, 30 };
    int n = 10;
    printf("%d\n", cutTheRod(p, n));

    return 0;
}
