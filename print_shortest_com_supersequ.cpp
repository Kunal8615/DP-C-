#include <iostream>
#include <stdlib.h>
using namespace std;
#include <climits>
#include <algorithm>

int t[100][100];
string print_scs(string a,string b , int size_a,int size_b){
string str;

// main content 

for (int i = 0; i <= size_a; i++) {
    for (int j = 0; j <= size_b; j++) {
        if (i == 0 || j == 0)
            t[i][j] = 0; 
    }
    }

 for (int i = 1; i <= size_a; i++)
    {
        for (int j = 1; j <= size_b; j++)
        {
          
            if (a[i - 1] == b[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    int i = size_a;
    int j = size_b;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            str.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                str.push_back(b[j-1]);
                j--;
            }          
            else{
                str.push_back(a[i-1]);
                i--;
            }
        }

    }

      while(i>0) {
        str.push_back(a[i-1]);
        i--;
    }
    while(j>0) {
        str.push_back(b[j-1]);
        j--;
    }

    reverse(str.begin(), str.end());
    return str;

}

int main(){
    {
    string a = "acee";
    int size_a = a.size();
    string b = "zabne";
    int size_b = b.size();
    cout << print_scs(a, b, size_a, size_b);
    return 0;
}
}
