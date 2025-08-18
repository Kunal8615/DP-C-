#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

int fab[100];

int fabonacci(int n){
if(n==0){
    return 0;
}
else if(n==1){
    return 1;
}

for(int i=2 ;i <=n ; i++){
    fab[i] = fabonacci(n-1) + fabonacci(n-2);
}


return fab[n];
};

int main(){
    int x;
    cout<<"enter the number ";
    cin >> x;
    cout<<fabonacci(x);


}