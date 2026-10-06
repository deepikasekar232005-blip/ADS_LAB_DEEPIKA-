#include <stdio.h>
#define MAX 20
typedef struct
{
    int u, v, w;
} Edge;

// Find the parent of a vertex
int find(int parent[], int i)
{
    return (parent[i] == i)
               ? i
               : (parent[i] = find(parent, parent[i]));
}

// Union two sets
void unionSet(int parent[], int x, int y)
{
    parent[y] = x;
}
int main()
{
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    Edge edges[e];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = i + 1; j < e; j++)
        {
            if (edges[i].w > edges[j].w)
            {
                Edge t = edges[i];
                edges[i] = edges[j];
                edges[j] = t;
            }
        }
    }

    // Initialize parent array
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;
    printf("Edges in MST:\n");
    int count = 0;

    // Select edges for MST
    for (int i = 0; i < e && count < n - 1; i++)
    {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        // Add edge if it does not form a cycle
        if (x != y)
        {
            printf("%d-%d (%d)\n",
                   edges[i].u,
                   edges[i].v,
                   edges[i].w);
            unionSet(parent, x, y);
            count++;
        }
    }
    return 0;
}


--OUTPUT
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (u v w):
0 1 2
0 2 3
1 2 1
1 3 4
2 3 5

Edges in MST:
1-2 (1)
0-1 (2)
1-3 (4)
