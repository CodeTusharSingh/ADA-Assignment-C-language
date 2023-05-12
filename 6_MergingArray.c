#include <stdio.h>

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }

    for (int p = 0; p < n1 + n2; p++)
    {
        for (int q = p + 1; q < n1 + n2; q++)
        {
            if (arr3[p] > arr3[q])
            {
                int temp = arr3[p];
                arr3[p] = arr3[q];
                arr3[q] = temp;
            }
        }
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);

    printf("Array after merging:\n");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}
