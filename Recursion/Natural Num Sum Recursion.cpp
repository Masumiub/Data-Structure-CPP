//Natural NumSum
#include<iostream>
using namespace std;

int naturalSum(int a);

int main(){
int n;
cout<< "Enter a positive number=";
cin>> n;
cout<< "Summation=" <<  naturalSum(n);

}

int naturalSum(int a){
if(a !=0){ return a + naturalSum(a-1); }
return 0;
}
