#include <iostream>
#include <stdlib.h>
#include <climits>
 // max no of way 
using namespace std;
int t[100][100];

int min_coin(int *coin,int coin_size,int sum){


    //inslization

     for (int i = 0; i <= coin_size; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                t[i][j] = INT_MAX -1;
            }
            if (j == 0)
            {
                t[i][j] = 0;
            }
            if(i==0 && j==0){
                t[i][j] = INT_MAX -1;
            }
        }
    }

    for (int i = 1; i <= sum; i++){
        if(i%coin[0] ==0){
            t[1][i] = i/coin[0];
        }
        else {
            t[1][i] = INT_MAX -1;
        }
    }
    

    // MAIN CODE 
    
    for (int i = 1; i <= coin_size; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(coin[i-1] <= sum){
                t[i][j] =    min(t[i][j - coin[i-1]] +1 , t[i-1][j] ); //only change
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
    int sum = 3;
    int coin_size = sizeof(coin) / sizeof(coin[0]);
  //  cout << coin_size;
    cout << min_coin(coin, coin_size, sum);
    return 0;
}
