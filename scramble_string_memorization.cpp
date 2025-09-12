#include <iostream>
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> t;


bool solve(string a,string b){


//map key 
    string temp =  a;
    temp.push_back(' ');
    temp.append(b);


if(t.find(temp) != t.end()){
    return t[temp];
}

//
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
    t[temp] = flag;
    return flag;
    
}

int main(){
    string a = "great";
    string b = "rgtea";

    if (a.length() != b.length()) {
        cout << "not scramble";
        return 0;
    }

    if (a.empty() && b.empty()) {
        cout << "empty string";
        return 0;
    }

    bool flag = solve(a,b);
   
    if(flag) cout << "sacramble";
    else cout << "not scrambled";

    return 0;
    
}