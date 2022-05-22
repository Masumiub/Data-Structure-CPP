#include<iostream>
#include<string>
using namespace std;

int main(){
int n;
cin>>n;
int a[n];
for(int i=0; i<n; i++){
cin>> a[i];
}
int largest=a[0];
int smallest=a[0];

for(int i=0; i<n; i++){
    if(largest<a[i]){
        largest=a[i];
    }
}
for(int i=0; i<n; i++){
    if(smallest>a[i]){
        smallest=a[i];
    }
}
cout<< "Sum :"<< largest+smallest;

return 0;
}
