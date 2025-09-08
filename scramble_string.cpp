#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool solve(string a,string b){

    if(a.compare(b)==0){
        return true;
    }

    if(a.length() <= 1){
        return false;
    }

    int n = a.length();
    bool flag = false;

    for (int  i = 1; i <= n-1; i++)
    {//in case of no swap
        bool case1 = solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)) ;
     //in case of  swap
        bool case2 = solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i));

        if(case1 || case2){
          flag = true;
        }
    } 
    return flag;
    
}

int main(){
    string a = "greatw";
    string b = "rgeat";

    if (a.length() != b.length()) {
        cout << "not scramble";
        return 0;
    }

    if (a.empty() && b.empty()) {
        cout << "empty string";
        return 0;
    }

    bool flag = solve(a,b);
   
    if(flag) cout << "acramble";
    else cout << "not scrambled";

    return 0;
    
}