#include<iostream>
using namespace std;

void merge_arrays(int *a1,int m,int *a2,int n){
    int new_size=m+n;

    for(int i =0; i<n; i++){
        a1[m+i] = a2[i];
    }
    for(int i =0; i<new_size; i++){
        cout<< a1[i]<< " ";
    }
}
int main(){
    int m =5;
    int *a1 = new int[m];

    int n =3;
    int *a2 = new int[n];

    for(int i =0 ; i<m; i++){
        cin>> a1[i];
    }

    for(int i =0 ; i<n; i++){
        cin>> a2[i];
    }

    merge_arrays(a1, m, a2, n);
    return 0;
}
