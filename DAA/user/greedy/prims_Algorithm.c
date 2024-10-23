#include <stdio.h>
#include <limits.h>

#define MAX 100

int n;
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array
int parent[MAX];   // Parent array

void prims() {
    int min, u = -1, v = -1;
    int k = n;
    while (k > 1) 
    {
        min = INT_MAX;
        for (int i = 0; i < n; i++) 
        {
            if (visited[i] == 1) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (adj[i][j] != -1 && visited[j] == 0) 
                    {
                        if (adj[i][j] < min) 
                        {
                            min = adj[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        visited[v] = 1;
        parent[v] = u;
        k--;
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (-1 for no edge):\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited and parent arrays
    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
        parent[i] = -1;
    }

    // Start from the first vertex
    visited[0] = 1;

    // Run Prim's algorithm
    prims();

    // Print the MST
    printf("Edge\tWeight\n");
    for (int i = 1; i < n; i++) 
    {
        if (parent[i] != -1) {
            printf("%d - %d\t%d\n", parent[i], i, adj[parent[i]][i]);
        }
    }

    return 0;
}
// Enter the number of vertices: 5
// Enter the adjacency matrix (-1 for no edge):
//  0  2 -1  6 -1
//  2  0  3  8  5
// -1  3  0 -1  7
//  6  8 -1  0  9
// -1  5  7  9  0
// Edge	Weight
// 0 - 1	2
// 1 - 2	3
// 0 - 3	6
// 1 - 4	5
