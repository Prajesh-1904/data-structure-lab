#include <stdio.h>
int p[10];
int find(int i) {
    while (p[i] != i)
    {
        i = p[i];
    }
    return i;
}
void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    p[a] = b;
}
void mst(int c[10][10], int n) {
    int mincost = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    int edges = 0;
    while (edges < n - 1) {
        int min = 9999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && c[i][j] < min) {
                    min = c[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        printf("Edge %d:(%d, %d) cost: %d \n", edges++, a, b, min);
        mincost += min;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    int c[10][10],n;
    printf("Enter the number of villages: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {    
            scanf("%d", &c[i][j]);
        }
    }
    mst(c, n);
    return 0;
}
