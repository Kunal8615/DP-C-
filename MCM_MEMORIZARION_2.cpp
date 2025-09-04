#include <bits/stdc++.h>
using namespace std;

int static t[100][100];

int solve(int *matrix, int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int cost = solve(matrix, i, k) 
                 + solve(matrix, k + 1, j) 
                 + (matrix[i - 1] * matrix[k] * matrix[j]);

        mn = min(mn, cost);
    }

    t[i][j] = mn;  // ✅ final minimum store karo
    return t[i][j];
}

int main()
{
    int matrix[] = {40, 20, 30, 10, 30};
    int size_matrix = (sizeof(matrix) / sizeof(matrix[0])) - 1;

    // memo table initialize
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            t[i][j] = -1;

    int i = 1;
    int j = size_matrix;

    cout << "Minimum Cost: " << solve(matrix, i, j) << endl;
    return 0;
}
