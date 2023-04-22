#include <stdio.h>
#include <math.h>

void merge(int arr[], int left, int mid, int right)
{
    int p = mid - left + 1;
    int q = right - mid;
    int arr1[p], arr2[q];
    for (int i = 0; i < p; i++)
    {
        arr1[i] = arr[left + i];
    }
    for (int j = 0; j < q; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < p && j < q)
    {
        if (arr1[i] >= arr2[j])
        {
            arr[k] = arr2[j];
            j++;
        }
        else
        {
            arr[k] = arr1[i];
            i++;
        }
        k++;
    }
    while (i < p)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < q)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void divide(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        divide(arr, left, mid);
        divide(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {9, 9, 5, 63, 74, 0, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr, 0, n - 1);
    for (int k = 0; k < n; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}