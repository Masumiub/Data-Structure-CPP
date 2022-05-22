#include<iostream>
using namespace std;

/*
print this using 2d dynamic array
1
2 3
4 5 6
7 8 9 10
*/

int main()
{
    int row=4;
    int col=4;


    int** A = new int*[row];
    int k=1;
    for (int i = 1; i <= row; i++) {
        A[i] = new int[k];
        k++;
    }

    int value =1;
    for (int i = 1; i <= row; i++)
    {

        for (int j = 1; j <= i; j++) {
            A[i][j] = value;
            value++;
        }
    }


    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++) {
           cout << A[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 1; i <= row; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
