#include<iostream>
using namespace std;
/*void factorial(int n){
    int fact=1;
    if(n<0){
        cout<<"invalid"<< endl;
    }
    else{
        for(int i=1; i<=n; i++){
            fact *=i;
        }
        cout<<fact;
    }
}
*/

int factorial_recur(int n){
    if(n==0){
        return 1;
    }
    return n*factorial_recur(n-1);

}
int factorial_recur2(int n){
   /* if(n>1){
       return 1*factorial_recur((n-1)+1);

    }
    return 1;*/
    //use i , i++ -- draw diagram..

}


int main(){
int n;
cin>> n;
//factorial(n);
//int x = factorial_recur(n);

int x = factorial_recur2(n);
cout<< x;
return 0;
}
