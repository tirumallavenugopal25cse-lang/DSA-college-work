#include <stdio.h>

int main()
{
    int n, graph[20][20], visited[20] = {0};
    int queue[20], front = 0, rear = 0;
    int start, i, j, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while(front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}