#include<iostream>
using namespace std;

int factorial(int i, int n ){
int res=1;
    while(i<=n){
        res = n*i;
        cout<< i<< "->"<< n<< "x"<< i<< "="<< res<< endl;
        i++;
        return factorial(i, n)*(n-1) ;
    }
}

int main(){
int n=5;
//cin>>n;
cout<< factorial(1, n);

return 0;
}
