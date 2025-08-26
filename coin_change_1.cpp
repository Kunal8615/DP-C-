#include <iostream>
#include <stdlib.h>

using namespace std;
int t[100][100];

int coin_change(int *coin, int coin_size, int sum)
{
    for (int i = 0; i <= coin_size; i++)
    {
        for (int j = 0; j <= sum; j++)
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

    // main content

    for (int i = 1; i <= coin_size; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(coin[i-1] <= sum){
                t[i][j] =  t[i][j - coin[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[coin_size][sum];
}

int main()
{
    int coin[] = {1, 2, 3};
    int sum = 5;
    int coin_size = sizeof(coin) / sizeof(coin[0]);
  //  cout << coin_size;
    cout << coin_change(coin, coin_size, sum);
    return 0;
}
