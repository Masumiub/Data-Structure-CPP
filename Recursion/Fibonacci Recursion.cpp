#include <iostream>

using namespace std;

int Fibonacci(int n,int t1,int t2)
{
    if ( n == 0 )
        {return t1;}
    else if(n == 1)
        {return t2;}
    else if(n == 0 || n == 1)
        { return t1+t2;}
    else
      return ( Fibonacci(n-1, t1, t2) + Fibonacci(n-2, t1, t2));
}

int print(int n,int t1,int t2){
    int i=0;
    for (int  c = 1 ; c <= n ; c++ )
   {
      cout<< Fibonacci(i, t1, t2)<< " ";
      i++;
   }
}

int main()
{
    int n, i = 0, c;
    int t1, t2;
    cin>> t1>>t2;
    cin>>n;
    print(n, t1, t2);
    Fibonacci(n, t1, t2);
    return 0;
}
