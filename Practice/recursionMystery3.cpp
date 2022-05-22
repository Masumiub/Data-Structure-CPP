#include<iostream>
using namespace std;

int recursionMystery3(int n){
    if(n<0){
        return -recursionMystery3(-n);
    }else if(n<10){
        return (n+1)%10;
    }
    else{
        return 100*recursionMystery3(n/10)+(n+1)%10;
    }

}

int main(){
cout<< recursionMystery3(89294);
return 0;
}
