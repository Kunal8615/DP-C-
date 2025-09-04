#include <stdlib.h>
#include <iostream>
using namespace std;

int t[100][100];

int long_sub(string a,string b,int size_a,int size_b){
    
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
    string a = "axy";
    int size_a = a.size();
    string b = "adxfpy";
    int size_b = b.size();
    cout<<size_b<<endl;
   int lcs = long_sub(a,b,size_a,size_b);
  // cout<<lcs << endl<<a.length();
   if(lcs == a.length()){
    cout<<"true";
   }
   else{
 cout<<"false";
   }

   
}