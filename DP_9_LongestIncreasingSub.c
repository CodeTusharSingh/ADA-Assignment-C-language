#include <stdio.h>

#define MAX_SIZE 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestIncreasingSubsequence(int arr[], int size) {
    int dp[MAX_SIZE];  // Dynamic programming array to store the lengths of longest increasing subsequences
    int maxLen = 1;  // Initialize the maximum length to 1

    // Base case: The longest increasing subsequence of a single element is 1
    for (int i = 0; i < size; i++) {
        dp[i] = 1;
    }

    // Compute the lengths of longest increasing subsequences for each position
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            // If the current element is greater than the previous element,
            // update the length of the longest increasing subsequence
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // Update the maximum length
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int longestLen = longestIncreasingSubsequence(arr, size);

    printf("Longest increasing subsequence length: %d\n", longestLen);

    return 0;
}
