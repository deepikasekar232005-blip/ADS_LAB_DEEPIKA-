#include <stdio.h>
#define SIZE 20
int q[SIZE];
int front = 0, rear = 0;
// Add vertex to queue
void enqueue(int v)
{
    q[rear++] = v;
}

// Remove vertex from queue
int dequeue()
{
    return q[front++];
}

// Check if queue is empty
int isEmpty()
{
    return front == rear;
}
int main()
{
    int n, adj[20][20], visited[20] = {0}, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter start vertex (0-%d): ", n - 1);
    scanf("%d", &start);
    printf("BFS Traversal: ");
    visited[start] = 1;
    enqueue(start);
    while (!isEmpty())
    {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

    return 0;
}


--OUTPUT
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 1
0 0 1 1 0
Enter start vertex (0-4): 0
BFS Traversal: 0 1 2 3 4
