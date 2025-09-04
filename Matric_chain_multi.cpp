#include <stdlib.h>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;


int solve(int *matrix , int i, int j){

    int temp ;
    int mn = INT_MAX;
    if(i>=j){
        return 0;
    }
    for (int k = i; k <= j-1; k++)
    {
      temp = solve(matrix,i,k) + solve(matrix,k+1,j) + (matrix[i-1] * matrix[k] * matrix[j]) ;

      if(temp<mn){
        mn =temp ;
      }
    }

    return mn;

}

int main(){
    int matrix[] = {40,20,30,10,30};
    int size_matrix = (sizeof(matrix)/sizeof(matrix[0])) - 1;
    //cout<<size_matrix; 
    int i = 1 ; 
    int j = size_matrix;
    cout<<solve(matrix,i,j);
    return 0;
}