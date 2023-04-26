#include <stdio.h>
#include <stdlib.h>

#define size 2
struct data
{
    int value;
    int key;
};

struct hashtable
{
    struct data *table[size];
};

int hashFunction(int x, int n)
{
    return x % n;
}

struct hashtable *bucket()
{
    struct hashtable *hs = malloc(sizeof(struct hashtable));
    for (int i = 0; i < size; i++)
    {
        hs->table[i] = NULL;
    }
    return hs;
}

void insert(int k, int v, struct hashtable *hs)
{
    int pos = hashFunction(k, size);
    struct data *node = malloc(sizeof(struct data));
    node->key = k;
    node->value = v;
    if (hs->table[pos] == NULL)
    {
        hs->table[pos] = node;
        return;
    }
    else
    {
        int i = pos;
        int c = 0;
        while (c < size)
        {
            if (hs->table[i] == NULL)
            {
                hs->table[i] = node;
                return;
            }
            i = (i + 1) % size;
            c++;
        }
        printf("No space left in hashtable....... \n");
    }
}

int search(struct hashtable *hs, int key)
{
    int pos = hashFunction(key, size);
    struct data *node = hs->table[pos];
    int i = pos;
    int c = 0;
    while (c < size)
    {
        if (hs->table[i]->key == key)
        {
            return i;
        }
        i = (i + 1) % size;
        c++;
    }
    return -1;
}

void delete(struct hashtable *hs, int key)
{
    int pos = hashFunction(key, size);
    struct data *node = hs->table[pos];
    int i = pos;
    int c = 0;
    while (c < size)
    {
        if (hs->table[i] == NULL)
        {
            return;
        }
        if (hs->table[i]->key == key)
        {
            free(hs->table[i]);
            hs->table[i] = NULL;
            int j = (i + 1) % size;
            while (hs->table[j] != NULL)
            {
                struct data *node = hs->table[j];
                hs->table[j] = NULL;
                insert(hs, node->key, node->value);
                free(node);
                j = (j + 1) % size;
            }
            return;
        }
        i = (i + 1) % size;
        c++;
    }
}

int main()
{
    int key;
    int value;
    struct hashtable *hs = bucket();
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the value you want to insert in hash table: ");
        scanf("%d", &value);
        printf("Enter the key for the value: ");
        scanf("%d", &key);
        insert(key, value, hs);
    }
    printf("%d", search(hs, 7));
    return 0;
}