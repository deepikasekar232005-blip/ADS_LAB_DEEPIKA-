#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int key, degree, mark;
    struct Node *parent, *child, *left, *right;
} Node;
Node *min = NULL;

// Create new node
Node *newNode(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));

    n->key = key;
    n->degree = 0;
    n->mark = 0;
    n->parent = NULL;
    n->child = NULL;
    n->left = n;
    n->right = n;

    return n;
}

// Insert node into Fibonacci heap
void insert(int key)
{
    Node *n = newNode(key);
    if (!min)
    {
        min = n;
    }
    else
    {
        n->left = min;
        n->right = min->right;
        min->right->left = n;
        min->right = n;
        if (n->key < min->key)
            min = n;
    }
}

// Display root list
void display()
{
    if (!min)
    {
        printf("Heap empty\n");
        return;
    }
    Node *t = min;
    printf("Root List: ");
    do
    {
        printf("%d ", t->key);
        t = t->right;
    }
    while (t != min);
    printf("\n");
}
int main()
{
    int choice, key;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Get Min\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            insert(key);
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            if (min)
                printf("Minimum = %d\n", min->key);
            else
                printf("Heap empty\n");
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
--OUTPUT
1. Insert
2. Display
3. Get Min
4. Exit
Enter choice: 1
Enter key: 25

Enter choice: 1
Enter key: 7

Enter choice: 1
Enter key: 40

Enter choice: 2
Root List: 25 7 40

Enter choice: 3
Minimum = 7
Enter choice: 4
