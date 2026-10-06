#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key, height;
    struct Node *left, *right;
} Node;

// Get height of a node
int h(Node *n)
{
    return n ? n->height : 0;
}

// Find maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Create a new node
Node *newNode(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));

    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;

    return n;
}
// Right rotation
Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T = x->right;
    x->right = y;
    y->left = T;
    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}

// Left rotation
Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T = y->left;
    y->left = x;
    x->right = T;
    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
    return y;
}

// Get balance factor
int getBalance(Node *n)
{
    return n ? h(n->left) - h(n->right) : 0;
}

// Insert a node into AVL tree
Node *insert(Node *node, int key)
{
    // Normal BST insertion
    if (!node)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // Update height
    node->height = 1 + max(h(node->left), h(node->right));

    // Get balance factor
    int bal = getBalance(node);

    // LL Case
    if (bal > 1 && key < node->left->key)
        return rotateRight(node);

    // RR Case
    if (bal < -1 && key > node->right->key)
        return rotateLeft(node);

    // LR Case
    if (bal > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL Case
    if (bal < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Inorder traversal
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main()
{
    Node *root = NULL;
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Inorder Traversal (Balanced Tree): ");
    inorder(root);
    return 0;
}


--OUTPUT
Enter number of nodes: 5
Enter 5 values: 20 10 60 50 30
Inorder Traversal (Balanced Tree): 10 20 30 50 60
