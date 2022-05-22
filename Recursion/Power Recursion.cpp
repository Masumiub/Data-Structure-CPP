//No- 05//Write a program that will take the two positive numbers and calculate the power using recursion.
#include<iostream>
#include<math.h>
using namespace std;

int power(int a,int b){
if(b != 0){
    return (a*power(a, b-1));
}
else{
    return 1;
}

}

int main(){
int n, m;
cin>>n>> m;
int pod;
pod=power(n,m);
cout<< pod;
return 0;
}
