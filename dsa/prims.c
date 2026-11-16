
#include <stdio.h>
#define MAX 20
#define INF 9999

int main() {
    int n, a[MAX][MAX], visited[MAX] = {0};
    int i, j, u, v, min, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)
                a[i][j] = INF;
        }

    visited[0] = 1;

    printf("Edges in MST:\n");

    for(i = 0; i < n - 1; i++) {
        min = INF;

        for(j = 0; j < n; j++)
            if(visited[j])
                for(int k = 0; k < n; k++)
                    if(!visited[k] && a[j][k] < min) {
                        min = a[j][k];
                        u = j;
                        v = k;
                    }

        if(min == INF) {
            printf("Graph is disconnected\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);
        visited[v] = 1;
        cost += min;
    }

    printf("Total cost = %d\n", cost);
    return 0;
}
