#include <stdio.h>
#include <stdlib.h>
#define ORDER 4
struct BPlusNode
{
    int keys[ORDER];
    struct BPlusNode *child[ORDER + 1];
    struct BPlusNode *next;
    int count;
    int isLeaf;
};
struct BPlusNode *root = NULL;

// Create a new B+ Tree node
struct BPlusNode *createNode(int isLeaf)
{
    struct BPlusNode *newNode;
    newNode = (struct BPlusNode *)malloc(sizeof(struct BPlusNode));
    newNode->count = 0;
    newNode->isLeaf = isLeaf;
    newNode->next = NULL;
    for (int i = 0; i <= ORDER; i++)
        newNode->child[i] = NULL;
    return newNode;
}

// Insert a key
void insert(int key)
{
    struct BPlusNode *leaf;
    int i;

    // Create root if tree is empty
    if (root == NULL)
    {
        root = createNode(1);
        root->keys[0] = key;
        root->count = 1;
        return;
    }
    leaf = root;

    // Find the appropriate leaf node
    while (!leaf->isLeaf)
    {
        i = 0;
        while (i < leaf->count && key >= leaf->keys[i])
            i++;
        leaf = leaf->child[i];
    }

    // Insert key in sorted order
    i = leaf->count - 1;
    while (i >= 0 && leaf->keys[i] > key)
    {
        leaf->keys[i + 1] = leaf->keys[i];
        i--;
    }
    leaf->keys[i + 1] = key;
    leaf->count++;

    // Simple leaf split for demonstration
    if (leaf->count == ORDER)
    {
        struct BPlusNode *newLeaf;
        int mid = ORDER / 2;

        newLeaf = createNode(1);
        for (i = mid; i < leaf->count; i++)
            newLeaf->keys[i - mid] = leaf->keys[i];
        newLeaf->count = leaf->count - mid;
        leaf->count = mid;

        // Link the new leaf
        newLeaf->next = leaf->next;
        leaf->next = newLeaf;
    }
}

// Display leaf nodes
void display()
{
    struct BPlusNode *temp = root;

    if (temp == NULL)
    {
        printf("B+ Tree is empty.\n");
        return;
    }

    // Move to the first leaf
    while (!temp->isLeaf)
        temp = temp->child[0];
    printf("B+ Tree Leaf Nodes:\n");

    // Traverse all leaf nodes
    while (temp != NULL)
    {
        printf("[ ");

        for (int i = 0; i < temp->count; i++)
            printf("%d ", temp->keys[i]);
        printf("] ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n, key;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}


--OUTPUT
Enter number of keys: 6
Enter the keys:
10 20 5 15 25 30

B+ Tree Leaf Nodes:
[ 5 10 ] [ 15 20 25 30 ]
