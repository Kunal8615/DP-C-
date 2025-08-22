#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>
using namespace std;
int t[100][100];

int min_sub_diff(int *arr, int arr_size, int arr_sum)
{

    int partial_arr[arr_size / 2];

    for (int i = 0; i <= arr_size; i++)
    {
        for (int j = 0; j <= arr_sum; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            else if (j == 0)
            {
                t[i][j] = 1;
            }
            else if(i == 0 && j ==0){
                 t[i][j] = 1;
            }
        }
    }

    // subarray
    for (int i = 1; i <= arr_size; i++)
    {
        for (int j = 1; j <= arr_sum; j++)
        {
            if (arr[i] <= arr_sum)
            {
                t[i][j] = t[i-1][j - arr[i]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
          // cout<<t[i][j];
        }
    }

    //check print 
      for (int i = 0; i <= arr_size; i++)
    {
        for (int j = 0; j <= arr_sum; j++)
        {
            
           cout<< "|" << t[i][j]<<"|";
         
        }
     cout<<endl;
    }

    // selection half  set  last row


    for (int i = 0; i <= arr_sum; i++)
    {
            if(t[arr_size][i] ==1){
            partial_arr[i] = i;
            }
    }

    // calcualting partial arr size
    int size_partial_arr = sizeof(partial_arr) / sizeof(partial_arr[0]);
    // main formula for it
    for (int i = 0; i <=size_partial_arr ; i++)
    {
        cout << partial_arr[i] << "-";
    }

    int mn = INT_MAX;
    for (int j = 0; j <= size_partial_arr; j++)
    {
        mn = min(mn, (arr_sum - (2 * partial_arr[j])));
    }

   // return mn;
}

int main()
{
    int arr[3] = {1, 2, 7};
    int arr_sum = 0;
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i <= arr_size; i++)
    {
        arr_sum += arr[i];
    }

    cout << min_sub_diff(arr, arr_size, arr_sum);
    cout << arr_sum;
    return 0;
}