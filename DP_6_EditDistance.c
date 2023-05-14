#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int editDistance(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);

    int dp[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";

    int distance = editDistance(str1, str2);

    printf("Edit Distance: %d\n", distance);

    return 0;
}
