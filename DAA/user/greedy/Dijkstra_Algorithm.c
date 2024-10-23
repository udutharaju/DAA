#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Global variables
int adj[MAX][MAX];  // Adjacency matrix
int p[MAX];         // Parent array for storing shortest path
int v[MAX];         // Visited array
int cost[MAX];      // Cost array
int n;              // Number of vertices

// Function prototypes
int findMinNode();
void dijkstra(int src);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (-1 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == -1) {
                adj[i][j] = INF; // Use INF to represent no edge
            }
        }
    }
     
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        v[i] = -1;  // -1 means not visited
        p[i] = -1;  // -1 means no parent
        cost[i] = INF; // Initialize cost array to INF
    }
    cost[src] = 0; // Distance from source to itself is 0

    // Run Dijkstra's algorithm
    dijkstra(src);

    // Print the result
    printf("Vertex\tCost\tParent\n");
    for (int i = 0; i < n; i++) {
        if (cost[i] == INF) {
            printf("%d\tINF\t%d\n", i, p[i]);
        } else {
            printf("%d\t%d\t%d\n", i, cost[i], p[i]);
        }
    }

    return 0;
}

// Function to find the node with the minimum cost that has not been visited
int findMinNode() {
    int min = INF;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (v[i] == -1 && cost[i] < min) {
            min = cost[i];
            index = i;
        }
    }

    return index;
}

// Function that implements Dijkstra's algorithm
void dijkstra(int src) {
    int k = n;
    while (k > 0) {
        int i = findMinNode();
        v[i] = 1;

        for (int j = 0; j < n; j++) {
            if (adj[i][j] != INF && v[j] == -1) {
                if (cost[j] > cost[i] + adj[i][j]) {
                    cost[j] = cost[i] + adj[i][j];
                    p[j] = i;
                }
            }
        }

        k--;
    }
}
