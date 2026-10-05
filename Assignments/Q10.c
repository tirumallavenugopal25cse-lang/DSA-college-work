#include <stdio.h>

#define INF 9999

int main()
{
    int n, cost[20][20], dist[20], visited[20] = {0};
    int source, i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for(i = 0; i < n; i++)
        dist[i] = cost[source][i];

    dist[source] = 0;
    visited[source] = 1;

    for(count = 1; count < n; count++)
    {
        min = INF;
        u = -1;

        for(i = 0; i < n; i++)
        {
            if(visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(i = 0; i < n; i++)
        {
            if(visited[i] == 0 &&
               cost[u][i] != 0 &&
               dist[u] + cost[u][i] < dist[i])
            {
                dist[i] = dist[u] + cost[u][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}