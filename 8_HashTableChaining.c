#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    int key;
    struct node *next;
    struct node *prev;
};

struct hashtable
{
    int size;
    struct node **table;
};

int hashFunction(int x, int n)
{
    return x % n;
}

struct hashtable *bucket(int size)
{
    struct hashtable *hs = malloc(sizeof(struct hashtable));
    hs->size = size;
    hs->table = malloc(sizeof(struct node *) * size);
    for (int i = 0; i < size; i++)
    {
        hs->table[i] = NULL;
    }
    return hs;
}

void insert(int k, int v, struct hashtable *hs)
{
    int pos = hashFunction(k, hs->size);
    struct node *list = malloc(sizeof(struct node));
    list->key = k;
    list->value = v;
    list->prev = NULL;
    list->next = hs->table[pos];
    if (hs->table[pos] != NULL)
    {
        hs->table[pos]->prev = list;
    }
    hs->table[pos] = list;
    printf("%d", list);
}

int *search(struct hashtable *hs, int key)
{
    int pos = hashFunction(key, hs->size);
    struct node *current = hs->table[pos];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return &(current->value);
        }
        current = current->next;
    }
    return NULL;
}

void delete(struct hashtable *hs, int key)
{
    int pos = hashFunction(key, hs->size);
    struct node *current = hs->table[pos];
    while (current != NULL)
    {
        if (current->key == key)
        {
            if (current->prev == NULL)
            {
                hs->table[pos] = current->next;
            }
            else
            {
                current->prev->next = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

int main()
{
    int key;
    int value;
    int size;
    printf("What size of the hash table do you prefer: ");
    scanf("%d", &size);
    printf("Enter the value you want to insert in hash table: ");
    scanf("%d", &value);
    printf("Enter the key for the value: ");
    scanf("%d", &key);
    struct hashtable *hs = bucket(size);
    insert(key, value, hs);
    printf("%d", search(hs, 7));
    return 0;
}