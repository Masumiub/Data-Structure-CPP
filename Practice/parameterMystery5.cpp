#include<iostream>
using namespace std;

int  parameterMystery5(int *d, int e, int &f){
    f+=10;

    *d =e+2;
    e--;
    cout<< e<< " "<< d<< " "<< *d<< " " << f<< endl;

    return e+f;
}

int main(){
int b=0;
int d=-1;
int e=5;
int f=2;

b=parameterMystery5(&d,e,f);
parameterMystery5(&f,d,e);
parameterMystery5(&b,f,d);


cout<< d<< " "<< e<< " "<< f<< " "<< b<< endl;
cout<< endl;
}
