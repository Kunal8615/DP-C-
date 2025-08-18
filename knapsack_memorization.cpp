#include <stdio.h>
#include <stdlib.h>

int t[100][100]; // DP table

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int wt[], int val[], int W, int n) {
    // Base case initialization
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][W];
}

int main() {
    int wt[] = {2, 1, 3, 2};
    int val[] = {12, 10, 20, 15};
    int W = 5;
    int n = sizeof(wt) / sizeof(wt[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(wt, val, W, n));
    return 0;
}
