#include<iostream>

using namespace std;

bool isprime(int n, int i)
{
    if(i==1) {
        return true;
    }
    if(n%i==0) {
        return false;
    }

    return isprime(n,i-1);
}

int main()
{
    int n;
    cin>>n;
    cout<<isprime(n,n/2);
}
