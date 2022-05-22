//Convert decimal to binary
#include<iostream>
using namespace std;

int convert(int a){
if(a == 0) { return 0; }
else{ return ((a%2)+10*convert(a/2)); }
}
int main(){
int n;
cin>>n;
int bi;
bi=convert(n);
cout<< "Converted="<< bi<< endl;
return 0;
}
