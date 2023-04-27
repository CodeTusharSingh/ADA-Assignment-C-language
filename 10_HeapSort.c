#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
};

struct tree *createTree(int value)
{
    struct tree *node = malloc(sizeof(struct tree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct tree *buildTree(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct tree *root = createTree(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

void traverse(struct tree *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    traverse(root->left);
    traverse(root->right);
}

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
    struct tree *root = buildTree(arr, 0, size - 1);
    printf("Tree : ");
    traverse(root);
    printf("\n");
    heapSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}