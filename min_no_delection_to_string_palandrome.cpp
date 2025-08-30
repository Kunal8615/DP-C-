#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int t[100][100];

int long_sub(string a,string  b,int size_a,int size_b){
    
    for(int i =0 ;i<=size_a;i++){
        for(int j = 0 ; j<= size_b;j++){
            if(i == 0 || j == 0) {
             t[i][j] = 0;
        }
        }
    }

     for(int i =1 ;i<=size_a;i++){
        for(int j = 1 ; j<= size_b;j++){

            if(a[i-1]==b[j-1]){ 
                t[i][j] = 1 + t[i-1][j-1]; 
            }
            else{
                 t[i][j]  = max(t[i-1][j],t[i][j-1]);
            }

        }
     }

     return t[size_a][size_b];


};

int main(){
    string str1 = "agbcba";
    int size_a = str1.size();
    string str2 = str1;
    int size_b = str2.size();;
  //  cout<<size_a;
    reverse(str2.begin(), str2.end());
    int result = long_sub(str1,str2,size_a,size_b);
    
   cout << (size_a - result) << endl; // print to console
    
    return 0; 
}