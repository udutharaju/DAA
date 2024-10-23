#include <stdio.h>
#include <limits.h>

#define MAX 100

int parent[MAX];
int find(int i);
void union1(int i, int j);
void kruskal(int n, int adj[MAX][MAX]);

int main() {
    int n;
    int adj[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    kruskal(n, adj);
    return 0;
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    if (i != j)
        parent[j] = i;
}

void kruskal(int n, int adj[MAX][MAX]) {
    int u, v, a, b, min;
    int ne = 1;
    int cost = 0;
     
    printf("The edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        min = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] < min && adj[i][j] != 0) {
                    min = adj[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (u != v) {
            union1(u, v);
            printf("%d to %d cost %d\n", a, b, min);
            cost += min;
            ne++;
        }

        adj[a][b] = adj[b][a] = INT_MAX;  
    }

    printf("\nMinimum cost = %d\n", cost);
}
