#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find the kth largest element using divide and conquer
int findKthLargest(int arr[], int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int pivot = partition(arr, low, high);

        if (pivot - low == k - 1)
            return arr[pivot];

        if (pivot - low > k - 1)
            return findKthLargest(arr, low, pivot - 1, k);

        return findKthLargest(arr, pivot + 1, high, k - pivot + low - 1);
    }

    return -1; // Return -1 if k is invalid
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;

    // Sort the array in non-increasing order
    quickSort(arr, 0, n - 1);

    int kthLargest = findKthLargest(arr, 0, n - 1, k);
    if (kthLargest != -1)
        printf("The %dth largest element is %d\n", k, kthLargest);
    else
        printf("Invalid value of k\n");

    return 0;
}
