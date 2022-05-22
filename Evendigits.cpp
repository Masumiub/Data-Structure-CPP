//evendigits
#include<iostream>
using namespace std;
int evendigit(int n){
    if(n==0){ return 0;}
    int last;
    last = n % 10;
    if(last%2 == 0){
        return 10 * evendigit(n/10) +last;
    }
    return evendigit(n/10);
}

int main(){
int n;
cin>> n;
int even;
even = evendigit(n);
cout<< "Even Numbers are :"<< even<< endl;
return 0;
}
