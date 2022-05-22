#include<iostream>
#include<string>
using namespace std;

void rev(int *arr, int y, int x){
int tmp;
if(y<=x){
    tmp=arr[y];
    arr[y]=arr[x];
    arr[x]=tmp;
    rev(arr, y+1,x-1);
}

}

int main(){
int n;
cin>>n;
int arr[n];

for(int i=0; i<n; i++){
cin>> arr[i];
}
rev(arr, 3,7);

for(int i=0; i<n; i++){
cout<< arr[i]<< " ";
}

}
