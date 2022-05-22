#include<iostream>
using namespace std;

void recursion(int n){
    if(n<=1){
        cout<< n;
    }
    else{
        cout<< n<< " = (";
        recursion(n/2+n%2);
        cout<< ", ";
        recursion(n/2);
        cout<<  ")";
    }
}

int main(){
recursion(7);
}
