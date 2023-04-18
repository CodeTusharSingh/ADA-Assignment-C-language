#include <stdio.h>

int binarySearch(int arr[], int left, int right, int s)
{
    int mid = (left + right) / 2;
    if (left > right)
    {
        return -1;
    }
    else
    {
        if (arr[mid] == s)
        {
            return s;
        }
        else if (arr[mid] > s)
        {
            return binarySearch(arr, left, mid - 1, s);
        }
        else if (arr[mid] < s)
        {
            return binarySearch(arr, mid + 1, right, s);
        }
    }
}

int main()
{
    int arr[] = {56, 7, 2, 639, 0, 54, 77};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int tmp;
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%d", binarySearch(arr, 0, n, s));
    return 0;
}