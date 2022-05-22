#include <iostream>
using namespace std;

void dynamic_array(int *&A){

    //
    for(int i=0; i<5; i++){
        cout<< A[i]<<" ";
    }
}

int main()
{
    int *A=new int[5];
    for(int i=0; i<5; i++){
        A[i]=i+2;
    }
    dynamic_array(A);

    char **grades = new char*[3];
    grades[0] = new char[3];
    grades[1] = new char[4];
    grades[2] = new char[2];



    /*for(int  i =0 ; i<3; i++){
       cin>> grades[0][i];
    }

    for(int  i =0 ; i<4; i++){
       cin>> grades[1][i];
    }

    for(int  i =0 ; i<2; i++){
       cin>> grades[2][i];
    }

    for(int  i =0 ; i<4; i++){
        for(int j =0; j<4; j++){
            cout<< grades[i][j]<< " ";
        }
        cout << endl;
    }*/
    return 0;
}
