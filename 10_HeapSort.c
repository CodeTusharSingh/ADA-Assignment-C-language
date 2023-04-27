#include <stdio.h>
#include <stdlib.h>

int Parent(int i)
{
    return (i - 1) / 2;
}
int Left(int i)
{
    return ((2 * i) + 1);
}
int Right(int i)
{
    return ((2 * i) + 2);
}

void maxHeapify(int arr[], int i, int n)
{
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r < n && arr[largest] < arr[r])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, n);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, n);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        maxHeapify(arr, 0, i);
    }
}

int main()
{
    int size;
    printf("Enter the size of tree: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the values of node: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
