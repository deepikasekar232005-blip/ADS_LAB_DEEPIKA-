#include <stdio.h>
#define INF 999
int main()
{
    int n, adj[20][20], dist[20], visited[20] = {0};
    int u, min;
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

    int start;
    printf("Enter start vertex: ");
    scanf("%d", &start);

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[start] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < n; count++)
    {
        min = INF;
        u = -1;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        // No more reachable vertices
        if (u == -1)
            break;
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int i = 0; i < n; i++)
        {
            if (adj[u][i] && !visited[i] &&
                dist[u] + adj[u][i] < dist[i])
            {
                dist[i] = dist[u] + adj[u][i];
            }
        }
    }
    printf("Shortest distances from %d:\n", start);
    for (int i = 0; i < n; i++)
    {
        printf("%d -> %d : %d\n", start, i, dist[i]);
    }
    return 0;
}



--OUTPUT
Enter number of vertices: 4
Enter adjacency matrix:
0 2 3 0
2 0 1 4
3 1 0 5
0 4 5 0
Enter start vertex: 0

Shortest distances from 0:
0 -> 0 : 0
0 -> 1 : 2
0 -> 2 : 3
0 -> 3 : 6
