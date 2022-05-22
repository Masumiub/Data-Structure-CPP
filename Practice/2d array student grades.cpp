#include <iostream>
using namespace std;

int main()
{
    char **grades = new char*[3];
    grades[0] = new char[3];
    grades[1] = new char[4];
    grades[2] = new char[2];

    for(int  i =0 ; i<3; i++){
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
    }
    return 0;
}
