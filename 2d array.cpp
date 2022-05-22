#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    //cout<<"Hello World";
    int n;
    cin>> n;

    int i, j;
    int *A = new int[n];

    //srand(time(0));
    for(i=0; i<n; i++){
        A[i] =rand()%100;

    }

    for(i=0; i<n; i++){
        cout<< A[i]<< " " ;

    }
 cout<< endl<< endl;
    for(i=0; i<n; i++){
        for(j=i+1; j<n ; j++)
            if(A[i] == A[j])
                cout<< A[j]<< " ";
    }




}
