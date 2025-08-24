#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t[100][100];

int count_sub_diff(int *arr, int size, int subset)
{
    // inslization
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= subset; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

    // main conten
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= subset; j++)
        {
            if (arr[i-1] <= j) {
                 t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
}
            else {
                 t[i][j] =  t[i-1][j];
            }
        }
    }
    return t[size][subset];
};

int main()
{
    int sum = 0;
    int arr[4] = {1, 1, 2, 3};
    int diff = 1;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    // cout<<sum<<endl;
    int subset = (diff + sum)/2;
    //cout << sum << endl;
    // cout << size << endl;
   cout << count_sub_diff(arr, size, subset);
return 0;
   
}