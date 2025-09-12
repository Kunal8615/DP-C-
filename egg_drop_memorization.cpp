#include <iostream>
#include <stdio.h>
#include  <algorithm>
#include <climits>
#include <iostream>
#include <cstring> 
using namespace std;

int t[1001][1001];

int egg_drop(int egg,int floor){

    int mn = INT_MAX;
    if(floor ==0 || floor==1){
        return floor;
    }

   if(t[egg][floor]!= -1){
        return t[egg][floor];
    }


    if(egg==1){
        return floor;
    }

    for (int k = 1; k <= floor; k++)
    {
        int temp = 1 + max(egg_drop(egg-1,k-1),egg_drop(egg,floor-k));
        mn = min(mn,temp);
       t[egg][floor] = mn;
    }
    return mn;
    
}

int main(){
    int egg =3 ;
    int floor = 5 ;
    memset(t, -1, sizeof(t));
    cout<<egg_drop(egg,floor);
    return 0;
}