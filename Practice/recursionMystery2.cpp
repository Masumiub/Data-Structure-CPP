#include<iostream>
using namespace std;

void recursionMystery2(int n){
    if(n<=1){
        cout<< ": ";
    }else{
        cout<< (n%2)<< " ";
        recursionMystery2(n/2);
        cout<< n<< " ";
    }

}

int main(){
recursionMystery2(46);
return 0;
}
