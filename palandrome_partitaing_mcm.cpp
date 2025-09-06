#include <bits/stdc++.h>
#include <iostream> 
#include <stdlib.h>
using namespace std;

bool palaindrome(string str,int i, int j){
   
     while (i < j) {
        if (str[i] != str[j]) return false;
        i++; j--;
    }
    return true;
}

int solve(string str , int i , int j){
    int mn = INT_MAX;
    if(i>= j){
        return 0;
    }

    if(palaindrome(str,i,j)==true){
        return 0;
    }

        for (int k = i; k <= j-1; k++){
            int temp = 1 + solve(str,i,k) + solve(str,k+1,j) ;
              mn = min(temp,mn);
        }
    
        return mn;
        
}

int main(){
    string str = "nitin";
    int i = 0;   
    int str_size = (str.size()) -1; 

  //  cout<<str_size;
    cout<<solve(str,i,str_size);
    return 0;
}
