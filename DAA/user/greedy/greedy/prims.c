#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

void prims(int n, int adj[MAX][MAX]);

int main() {
    int n;
    int adj[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    prims(n, adj);

    return 0;
}

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void prims(int n, int adj[MAX][MAX]) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
            if (adj[u][v] && mstSet[v] == false && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, adj[i][parent[i]]);
}
// 0 1 3 4
// 1 0 2 6
// 3 2 0 5
// 4 6 5 0