#include<iostream>
using namespace std;

int  parameterMystery4(int &a, int* b, int c){
    a--;
    c =c*2;
    cout<< c<< " "<< a<< " "<< *b<< endl;
    (*b)++;
    return a+c;
}

int main(){
int a=2;
int b=5;
int c=-3;
int d;

parameterMystery4(a,&b,c);
d=parameterMystery4(c,&a,b);
parameterMystery4(b,&d,a);


cout<< a<< " "<< b<< " "<< c<< " "<< d<< endl;
}
