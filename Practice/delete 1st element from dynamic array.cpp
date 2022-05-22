#include<iostream>
using namespace std;

int *delete_front(int arr[], int n){

    int *a = new int[n-1];
    for(int i=0; i<n-1; i++){
        a[i] = arr[i+1];
    }
    return a;
}

int main(){
    int n=5;
    int *arr = new int[n];
    cout<< "Enter "<< n<< " numbers: ";

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int *arr2=arr;

    arr= delete_front(arr, n);
    delete []arr2;

    for(int i=0; i<n-1; i++){
        cout<< arr[i]<< " ";
    }

return 0;
}
