
#include <stdio.h>
#define INF 9999

int main() {
    int n, a[20][20], d[20], visited[20] = {0};
    int i, j, u, min, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)
                a[i][j] = INF;
        }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for(i = 0; i < n; i++)
        d[i] = INF;

    d[src] = 0;

    for(i = 0; i < n; i++) {
        min = INF;
        u = -1;

        for(j = 0; j < n; j++)
            if(!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }

        if(u == -1) break;

        visited[u] = 1;

        for(j = 0; j < n; j++)
            if(!visited[j] && a[u][j] != INF &&
               d[u] + a[u][j] < d[j])
                d[j] = d[u] + a[u][j];
    }

    printf("Shortest distances:\n");
    for(i = 0; i < n; i++) {
        if(d[i] == INF)
            printf("%d -> Not reachable\n", i);
        else
            printf("%d -> %d\n", i, d[i]);
    }

    return 0;
}
