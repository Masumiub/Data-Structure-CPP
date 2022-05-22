#include <iostream>

using namespace std;

int main()
{
    int a[4] = {1,2,6,9};
    int b[4] = {-3,0,17,5};

    int c[4]; int d[4];

    for(int i=0; i<4; i++){
        if(i<2){
            c[i] = a[i];
            cout<< c[i]<< "  ";
        }
        else{
        c[i] = b[i];
        cout<< c[i]<< "  ";
        }
    }

    return 0;
}

