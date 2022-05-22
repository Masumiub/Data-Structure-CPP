#include<iostream>
using namespace std;

int main(){
    int a1[] = {1,5,7,8,9,11};
    int a2[] = {6,8,10,11,12};

    int s1 = sizeof(a1)/sizeof(a1[0]);
    int s2 = sizeof(a2)/sizeof(a2[0]);

    /*for(int i=0; i<s1; i++){
        cout<<a1[i]<< " ";
    }*/
    int i =0, j=0;

    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(a1[i] == a2[j]){
                cout<< a1[i]<< " ";
            }
        }
    }

    return 0;
}
