/*

HC Problem statement : 

Given an undirected graph, the task is to determine whether the graph contains 
a Hamiltonian cycle or not. If it contains, then prints the path.

HC Definition :     Hamiltonian Cycle or Circuit in a graph G is a cycle that 
visits every vertex of G exactly once and returns to the starting vertex.


*/

#include <stdio.h>
#include <stdbool.h>

bool flag = false;

void printt(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool isSafe(int graph[][5], int arr[], int pos, int v) {
    for (int j = 0; j < pos; j++) {
        if (arr[j] == v)
            return false;
    }
    if (graph[arr[pos - 1]][v] == 0) {
        return false;
    }
    return true;
}

void cycle(int arr[], int graph[][5], int pos, int src) {
    int n = 5; // Number of vertices
    if (pos == 0) {
        arr[0] = src;
        cycle(arr, graph, pos + 1, src);
        return;
    } else if (pos == n) {
        if (graph[arr[n - 1]][src] == 1) {
            flag = true;
            printt(arr, n);
            return;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (isSafe(graph, arr, pos, i)) {
                arr[pos] = i;
                cycle(arr, graph, pos + 1, src);
            }
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 1, 0, 1, 0}, 
        {1, 0, 1, 1, 1}, 
        {0, 1, 0, 0, 1}, 
        {1, 1, 0, 0, 1}, 
        {0, 1, 1, 1, 0}
    };

    printf("Enter src vertex: ");
    int src;
    scanf("%d", &src);

    int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = -1; // Initialize array with -1 to indicate unvisited positions
    }

    cycle(arr, graph, 0, src);

    if (!flag) {
        printf("HC doesn't exist\n");
    }

    return 0;
}
