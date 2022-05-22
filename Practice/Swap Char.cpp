#include<iostream>
using namespace std;

void SwapChar(int *a, int *b){ // pointer
    int tmp;
    tmp=*a;
    *a=*b;
    *b= tmp;
}

void SwapChar2(int &c, int &d){ // reference
    int tmp;
    tmp=c;
    c=d;
    d= tmp;
}

void SwapChar3(int a, int b){ // value
    int tmp;
    tmp=a;
    a=b;
    b= tmp;
}

int main(){
int a; int b;
cin>>a>>b;

SwapChar(&a, &b); // pointer
cout<<a<<b;
cout<< endl;
SwapChar2(a, b);// reference
cout<<a<<b;
cout<< endl;
SwapChar3(a, b);// call by value
cout<<a<<b;

return 0;
}
