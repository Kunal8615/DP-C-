#include <stdlib.h>

#include <iostream>

using namespace std;
 
int t[100][100];

bool sum_partition(int arr[],int n,int max){
 // insilization
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0; j <=max ; j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] = true;
            }
        }
    }
 for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <=max ; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
        }
    
return t[n][max];
}

int main(){
    int sum = 0;
    int arr[] = {1,5,11,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i<=size-1;i++){
        sum  =sum + arr[i];
    }
   // cout<<sum;
   if(sum%2 !=0){
    cout<<"not possible";
    return 0;
   }
   else if(sum % 2 ==0){
        bool result  = sum_partition(arr,size,sum/2);
        cout << result;
        return 0;   
   }
   }