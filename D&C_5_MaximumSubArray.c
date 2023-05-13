#include <stdio.h>
#include <limits.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to find the maximum subarray sum that crosses the midpoint
int maxCrossingSum(int arr[], int low, int mid, int high)
{
    // Find the maximum sum of the left subarray
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    // Find the maximum sum of the right subarray
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    // Return the sum of the left and right subarray
    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using divide-and-conquer
int maxSubarraySum(int arr[], int low, int high)
{
    // Base case: if there is only one element
    if (low == high)
        return arr[low];

    // Find the middle element
    int mid = (low + high) / 2;

    // Recursively find the maximum subarray sum for the left and right subarrays
    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid + 1, high);
    int crossSum = maxCrossingSum(arr, low, mid, high);

    // Return the maximum of the left subarray sum, right subarray sum, and cross subarray sum
    return max(max(leftSum, rightSum), crossSum);
}

// Test the algorithm
int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, 0, n - 1);
    printf("Maximum subarray sum is: %d\n", maxSum);

    return 0;
}
