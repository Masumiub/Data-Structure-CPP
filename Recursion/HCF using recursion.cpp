//No. 6//HCF using recursion
#include<iostream>
#include<math.h>
using namespace std;
int hcf(int x, int y){
if (y != 0){
    return hcf(y, x%y);
}

else{
    return x;
}

}

int main(){
int n, m, res;
cin>> n>>m;
res= hcf(n,m);
cout<< "H C F="<<res<< endl;
return 0;
}
