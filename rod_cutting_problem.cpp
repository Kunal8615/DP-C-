// using unbounded knapsack
#include <iostream>
#include <stdlib.h>
using namespace std;

int t[100][100];

int rod_cut(int *length, int *price, int size, int rod_length)
{

    // inslization
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= rod_length; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    // main content

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= rod_length; j++)
        {

            if(length[i-1] <= j){
                t[i][j] = max( price[i-1] + t[i][j - length[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[size][rod_length];
};

int main()
{
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 1, 2, 20};
    int size = sizeof(price) / sizeof(price[0]);
    int rod_length = 8;
    cout << rod_cut(length, price, size, rod_length);
    return 0;
}