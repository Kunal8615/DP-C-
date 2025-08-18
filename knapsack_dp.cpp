#include <iostream>
#include <cstring> // for memset
using namespace std;

int t[100][100]; 


int knapsack(int wt[], int val[], int w, int n) {
    // Base case
    if (n == 0 || w == 0)
        return 0;

    // If already computed, return value
    if (t[n][w] != -1)
        return t[n][w];

    // If weight of the item is less than or equal to remaining capacity
    if (wt[n - 1] <= w) {
        t[n][w] = max(
            val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
            knapsack(wt, val, w, n - 1)
        );
    }
    // If item can't be included
    else {
        t[n][w] = knapsack(wt, val, w, n - 1);
    }

    return t[n][w];
};

int main() {
    int wt[] = {2, 1, 3, 2};
    int val[] = {12, 10, 20, 15};
    int w = 5;  // Knapsack capacity
    int n = sizeof(wt) / sizeof(wt[0]);

    // Initialize DP table with -1
    memset(t, -1, sizeof(t));

    int maxValue = knapsack(wt, val, w, n);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
