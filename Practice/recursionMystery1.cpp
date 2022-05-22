#include<iostream>
using namespace std;

void recursionMystery1(int x, int y){
    if(y<=0){
        cout<< "0 ";
    }
    else if(x>y){
        cout<< x<< " ";
        recursionMystery1(x-y,y);
    }else{
        recursionMystery1(x,y-x);
        cout<< y<< " ";
    }


}

int main(){
recursionMystery1(3, 10);

}

