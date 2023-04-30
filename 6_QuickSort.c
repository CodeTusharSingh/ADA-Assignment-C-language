#include <stdio.h>

int quickSort(int arr[], int left, int right)
{
    int p = arr[left];
    int l = left + 1;
    int r = right;
    while (l <= r)
    {
        if (arr[l] > p)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            r--;
        }
        else
        {
            l++;
        }
    }
    int temp = arr[left];
    arr[left] = arr[r];
    arr[r] = temp;
    return r;
}

void divide(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = quickSort(arr, left, right);
        divide(arr, left, pivot - 1);
        divide(arr, pivot + 1, right);
    }
}

int main()
{
    int arr[] = {9, 9, 5, 63, 74, 0, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr, 0, n - 1);
    for (int k = 0; k < 8; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}
