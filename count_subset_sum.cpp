#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int t[100][100];

int count_subset_sum(int *arr,int size ,int sum){

//inslization

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= sum ; j++)
        {
            if(i==0){
                t[i][j] = 0;
            }
            else if(j==0){
                t[i][j] = 1;
            }
        }
        
    }
    
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(arr[i]<=j){
                t[i][j] = t[i-1][j - arr[i]] + t[i-1][j];
            }
            else {
                 t[i][j] =  t[i-1][j];
            }
        }
        
    }
    return t[size][sum];

}

int main(){
int arr[6] = {2,3,5,6,8,10};
int size_arr = sizeof(arr)/sizeof(arr[0]);
int sum = 11;
cout<< count_subset_sum(arr,size_arr,sum);
}