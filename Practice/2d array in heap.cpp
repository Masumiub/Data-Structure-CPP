#include <iostream>
#include<ctime>
using namespace std;

#define M 4
#define N 5


int main()
{

    int** A = new int*[M];


    for (int i = 0; i < M; i++) {
        A[i] = new int[N];
    }


    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
        }
    }


    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) {
           cout << A[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < M; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

