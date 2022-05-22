#include <iostream>
using namespace std;

int mul=1;
void mul_recursive(int arr[], int n, int i){
    //static int mul=1;
    if(n==0){
        return ;
    }
    else{
        mul *= arr[i];
        i++;
        mul_recursive(arr, n-1, i);
    }
    //return mul;
}

void multiply_it(int arr[], int n){
    int mul=1;
    for(int i=0; i<n; i++){
        mul *= arr[i];
    }
    cout<< mul;
}

void print_recursive(int arr[], int n, int i){
    if(n==0){
        return;
    }
    else{
        cout<< arr[i]<< endl;
        i++;
        print_recursive(arr, n-1, i);
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    print_recursive(arr, n, 0);

    //multiply_it(arr, n);
    mul_recursive(arr, n, 0);
    cout<< mul<< endl;
    return 0;
}
