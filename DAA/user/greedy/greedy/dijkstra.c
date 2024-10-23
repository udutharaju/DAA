#include <stdio.h>
#include <limits.h>

#define MAX 100

int findmin(int cost[], int visit[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visit[i] && cost[i] < min) {
            min = cost[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int visit[], int cost[], int parent[], int n, int adj[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        cost[i] = INT_MAX;
        visit[i] = 0;
        parent[i] = -1;
    }

    cost[0] = 0; // Assuming the start vertex is 0

    for (int k = 0; k < n - 1; k++) {
        int i = findmin(cost, visit, n);
        if (i == -1) break; // If no minimum found, exit loop

        visit[i] = 1;

        for (int j = 0; j < n; j++) {
            if (adj[i][j] != -1 && !visit[j]) {
                if (cost[j] > cost[i] + adj[i][j]) {
                    cost[j] = cost[i] + adj[i][j];
                    parent[j] = i;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

 
    int visit[MAX], cost[MAX], parent[MAX];
    dijkstra(visit, cost, parent, n, adj);

    printf("Vertex\tCost\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t", i, cost[i]);
        int p = i;
        while (p != -1) {
            printf("%d ", p);
            p = parent[p];
        }
        printf("\n");
    }

    return 0;
}
// 0 1 -1 4
// 1 0 2 6
// -1 2 0 3
// 4 6 3 0
