#include<iostream>
using namespace std;
int lcm(int a, int b);
int main(){
    int num, num1;
    cout<< "Enter 1st Num:";
    cin>> num;

    cout<< "Enter 2nd Num:";
    cin>> num1;

    cout<< lcm(num, num1);

}

int lcm(int a, int b){
    static int m=0;
    m= m+b;
    if(m%a==0 && m%b==0){
        return m;
    }
    return lcm(a,b);
}


