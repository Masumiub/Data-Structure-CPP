#include<iostream>
using namespace std;

/*int recurDivMod(int n){
    if(n<0){
        return recurDivMod(-n);
    }
    else if(n<10){
        return n;
    }
    else{
        return n%10+ recurDivMod(n/10);
    }
}*/
/*
int recurMinus(int x, int y){
    if(x<y){
        return x;
    }
    else{
        return recurMinus(x-y, y); //6, 2, // 4, 2// 2, 2// 0, 2
    }
}*/

void recurPrint(int x){
    if(x<10){
        cout<< x;
    }
    else{
        int y = x%10;
        cout<< y;
        recurPrint(x/10);
        cout<< y;
    }
}
int main(){
    //cout<< recurDivMod(82534);
    //cout<< recurMinus(50, 7);
    recurPrint(3842);
}
