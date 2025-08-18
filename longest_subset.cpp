#include <stdlib.h>
#include <iostream>
using namespace std;

int t[100][100];

int long_sub(char *a,char * b,int size_a,int size_b){
    
    for(int i =0 ;i<=size_a;i++){
        for(int j = 0 ; j<= size_b;j++){
            if(i == 0 || j == 0) {
             t[i][j] = 0;
        }
        }
    }


     for(int i =1 ;i<=size_a;i++){
        for(int j = 1 ; j<= size_b;j++){

            if(a[i]==b[j]){
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
    char a[] = "AGGTAB";
    int size_a = sizeof(a)/sizeof(a[0]);
    char b[] = "GXpXAYB";
    int size_b = sizeof(b)/sizeof(b[0]);
   cout<<long_sub(a,b,size_a,size_b);
}