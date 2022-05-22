#include<iostream>
using namespace std;

int sum=0;
int collapseArray(int arr[], int size){
    static int i=0;
    if(size==0){
        return sum;
    }
    else{
        sum += arr[i];
        i++;
        collapseArray(arr, size-1);
    }
    return sum;
}
int main(){
    int arr[]={3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<< collapseArray(arr,size)<< endl;
    return 0;
}
