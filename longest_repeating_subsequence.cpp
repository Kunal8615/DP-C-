#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
using namespace std;
int t[100][100];

int LRS(string a ,string b ,int size_a,int size_b){
for (int i = 0; i <= size_a; i++)
{
    for (int j = 0; j <= size_b; j++)
    {
        if(i==0 || j ==0){
            t[i][j] = 0;
        }
    }
    
}

for (int i = 1; i <= size_a; i++)
{
    for (int j = 1; j <= size_b; j++)
    {
        if(a[i-1] == b[j-1] && i!=j){
            t[i][j] = 1 + t[i-1][j-1];
        }
        else{
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }

    }
    
}

return t[size_a][size_b];

}

int main(){
    string a = "aabebcdd";
    int size_a = a.size();
    cout << LRS(a, a, size_a, size_a);
    return 0;
}