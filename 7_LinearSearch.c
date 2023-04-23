#include <stdio.h>

int linearSearch(int arr[], int n, int s)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            return s;
            c++;
        }
    }
    if (c == 0)
    {
        return -1;
    }
}

int main()
{
    int arr[] = {56, 7, 2, 639, 0, 54, 77};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 639;
    printf("%d", linearSearch(arr, n, s));
    return 0;
}