#include <stdio.h>
#define SIZE 20
int visited[SIZE];

// DFS function
void DFS(int adj[SIZE][SIZE], int n, int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] && !visited[i])
        {
            DFS(adj, n, i);
        }
    }
}
int main()
{
    int n, adj[SIZE][SIZE], start;
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
    printf("DFS Traversal: ");

    // Initialize visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    DFS(adj, n, start);
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
DFS Traversal: 0 1 3 4 2
