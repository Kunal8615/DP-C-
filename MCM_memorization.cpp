#include <stdlib.h>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
int static t[100][100];
int solve(int *matrix, int i, int j)
{


    int mn = INT_MAX;
    if (i >= j)
    {
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }
    for (int k = i; k <= j - 1; k++)
    {
        t[i][j] = solve(matrix, i, k) + solve(matrix, k + 1, j) + (matrix[i - 1] * matrix[k] * matrix[j]);

        if (t[i][j] < mn)
        {
            mn = t[i][j];
        }
    }

    return mn;
}

int main()
{
    int matrix[] = {40, 20, 30, 10, 30};
    int size_matrix = (sizeof(matrix) / sizeof(matrix[0])) - 1;
    // cout<<size_matrix;
    //int t[size_matrix][size_matrix];
    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j <= size_matrix; j++)
        {
            t[i][j] = -1;
        }
    }

    int i = 1;
    int j = size_matrix;
    cout << solve(matrix, i, j);
    return 0;
}