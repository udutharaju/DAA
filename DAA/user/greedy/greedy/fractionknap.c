#include <stdio.h>

#define MAX 100

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to swap double elements
void swap_double(double arr[], int i, int j) {
    double temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to calculate the maximum value for the fractional knapsack problem
double ks(int wt[], int val[], int w, int n) {
    double rv = 0.0;
    double res[MAX];
    for (int i = 0; i < n; i++) {
        res[i] = (double)val[i] / wt[i];
    }

    // Sort items by value-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (res[j] < res[j + 1]) {
                swap_double(res, j, j + 1);
                swap(wt, j, j + 1);
                swap(val, j, j + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (wt[i] <= w) {
            rv += val[i];
            w -= wt[i];
        } else {
            rv += ((double)w / wt[i]) * val[i];
            break;
        }
       // printf("Current total value: %.2f\n", rv);  // Print current total value
    }

    return rv;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[MAX];
    int val[MAX];
    int a[n];

    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    int w;
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &w);

    double max_value = ks(wt, val, w, n);
    printf("The maximum value of items that can be carried: %.2f\n", max_value);

    return 0;
}
