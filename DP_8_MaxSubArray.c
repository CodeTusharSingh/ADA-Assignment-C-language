#include <stdio.h>

#define MAX_SIZE 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSumSubarray(int arr[], int size) {
    int dp[MAX_SIZE];  // Dynamic programming array to store the maximum sum ending at each position
    int maxSum = arr[0];  // Initialize the maximum sum to the first element

    // Base case: The maximum sum ending at the first position is the first element
    dp[0] = arr[0];

    // Compute the maximum sum ending at each position
    for (int i = 1; i < size; i++) {
        // Choose between extending the previous subarray or starting a new subarray
        dp[i] = max(arr[i], arr[i] + dp[i - 1]);
        // Update the maximum sum
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSumSubarray(arr, size);

    printf("Maximum sum subarray: %d\n", maxSum);

    return 0;
}
