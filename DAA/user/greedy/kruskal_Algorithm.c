#include <stdio.h>
#include <limits.h>

#define MAX 100

int adj[MAX][MAX];
int parent[MAX];

// Function to find the edge with the minimum weight
void findminedge(int n, int *u, int *v) 
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (adj[i][j] < min && adj[i][j] != -1) 
            {
                min = adj[i][j];
                *u = i;
                *v = j;
            }
        }
    }
}

// Function to find the parent of a node using path compression
int findparent(int k) {
    while (k != parent[k]) {
        k = parent[k];
    }
    return k;
}

// Function to check if adding an edge creates a loop
int checkloop(int u, int v) {
    int pu = findparent(u);
    int pv = findparent(v);
    if (pu == pv)
        return 0;
    else
        parent[pv] = pu;
    return 1;
}

// Kruskal's algorithm implementation
void kruskal(int n) {
    int k = n - 1; // number of edges to be added
    int u, v, i;
    int min_cost = 0;

    while (k > 0) 
    {
        findminedge(n, &u, &v);
        i = checkloop(u, v);
        if (i == 1) {
            printf("Edge: %d - %d==%d\n", u, v,adj[u][v]);
            min_cost += adj[u][v];
            k--;
        }
        adj[u][v] = adj[v][u] = -1; // mark edge as used
    }
    printf("Minimum Cost: %d\n", min_cost); 
}

int main() {
    int n, e, u, v, w;

    //nitialize adjacency matrix to -1 (indicating no edges)
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = -1;
        }
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u, v) and their weights:\n");
    for (int i = 0; i < e; i++) 
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = adj[v][u] = w;
    }

    // Initialize parent array for union-find
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("The edges in the Minimum Spanning Tree are:\n");
    kruskal(n);

    return 0;
}
// Enter the number of vertices: 4
// Enter the number of edges: 5
// Enter the edges (u, v) and their weights:
// 0  1 10
// 0  2  6
// 0  3  5
// 1  3 15
// 2  3  4
// The edges in the Minimum Spanning Tree are:
// Edge: 2 - 3==4
// Edge: 0 - 3==5
// Edge: 0 - 1==10
// Minimum Cost: 19

