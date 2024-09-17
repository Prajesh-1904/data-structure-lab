#include <stdio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int graph[MAX][MAX], int n, int start) 
{
    int cost[MAX][MAX], distance[MAX], visited[MAX], pred[MAX];
    int count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];
        }
    }
    for (i = 0; i < n; i++) 
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1) 
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) 
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        }
        count++;
    }
    for (i = 0; i < n; i++)
    {
        if (i != start) 
        {
            printf("\nDistance from node %d to node %d: %d", start, i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != start);
        }
    }
}
int main() 
{
    int graph[MAX][MAX], i, j, n, u;
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &u);
    dijkstra(graph, n, u);
    getch();
    return 0;
}
