#include<iostream>
using namespace std;

int main(){
int n = 1000000000;
int *arr = new int[n];

int *sum = new int; // use unsigned long long int
*sum =0;

for(int i=0; i<n; i++){
    arr[i]=i;
    *sum += arr[i];
}

cout<< *sum<< endl;

delete []arr;
return 0;

}
