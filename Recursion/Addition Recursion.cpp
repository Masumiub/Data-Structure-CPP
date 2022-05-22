#include<iostream>
using namespace std;

int res;

int R_add(int m, int n){
    if(n==0) return m;
    res = R_add(m, n-1)+1;
    return res;
}

int main(){
    int a =4, b=7;
    cout<< R_add(4, 7);
}
