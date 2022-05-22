//Factorial of a Number Using Recursion
#include<iostream>
#include<math.h>
using namespace std;
long int factorial(int a){
if(a>=1){
    return a*factorial(a-1);
}
else{
return 1;
}
}

int main(){
int n;
long int factor;
cin>>n;
factor=factorial(n);
cout<< factor<< endl;
return 0;
}
