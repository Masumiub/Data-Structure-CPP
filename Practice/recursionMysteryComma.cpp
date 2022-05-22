#include<iostream>
using namespace std;

void recursionMysteryComma(int x, int y){
if(y==1){
cout<< x;
}
else{
    cout<< (x*y)<< ", ";
    recursionMysteryComma(x, y-1);
    cout<< ", "<< (x*y);
}

}

int main(){
recursionMysteryComma(3, 4);

}
