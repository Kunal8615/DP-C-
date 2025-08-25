#include <iostream>
using namespace std;

// Recursive function for 0/1 Knapsack
int knapsack(int wt[], int val[], int w, int n) {
    // Base case
    if (n == 0 || w == 0)
        return 0;

   
    if (wt[n - 1] <= w) {
        return max(
            val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
            knapsack(wt, val, w, n - 1)
        );
    }
    // If item can't be included
    else {
        return knapsack(wt, val, w, n - 1);
    }
}

int main() {
    int wt[] = {2, 1, 3, 2};
    int val[] = {12, 10, 20, 15};
    int w = 5;  // Knapsack capacity
    int n = sizeof(wt) / sizeof(wt[0]);

    int maxValue = knapsack(wt, val, w, n);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
