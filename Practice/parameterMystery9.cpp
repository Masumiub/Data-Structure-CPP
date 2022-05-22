#include<iostream>
using namespace std;

int  parameterMystery9(int* b, int &c, int a){
    (*b)++;
    c +=3;
    a +=5;

    cout<< c<< " "<< a<< " "<< *b<< endl;

    return a;
}

int main(){

int a=10;
int b=200;
int c=3000;
//int f;

parameterMystery9(&a,b,c);
int d = parameterMystery9(&b,c,a);

//parameterMystery9(&b,f,d);


cout<< a<< " "<< b<< " "<< c<< " "<< d<< endl;


cout<< endl;
}
