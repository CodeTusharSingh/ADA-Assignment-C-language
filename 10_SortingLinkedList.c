#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to merge two sorted linked lists
Node *merge(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node *result = NULL;

    if (list1->data <= list2->data)
    {
        result = list1;
        result->next = merge(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = merge(list1, list2->next);
    }

    return result;
}

// Function to split the linked list into two halves
void splitList(Node *head, Node **front, Node **back)
{
    if (head == NULL || head->next == NULL)
    {
        *front = head;
        *back = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

// Function to perform merge sort on the linked list
void mergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *front;
    Node *back;

    if (head == NULL || head->next == NULL)
        return;

    splitList(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = merge(front, back);
}

// Function to insert a new node at the beginning of the linked list
void insertNode(Node **headRef, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to display the linked list
void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main()
{
    Node *head = NULL;

    // Insert some elements into the linked list
    insertNode(&head, 5);
    insertNode(&head, 2);
    insertNode(&head, 8);
    insertNode(&head, 3);
    insertNode(&head, 6);

    printf("Original list: ");
    displayList(head);

    mergeSort(&head);

    printf("Sorted list: ");
    displayList(head);

    return 0;
}
