#include <iostream>
using namespace std;

int main()
{
    int k=3;
    string **A = new string*[3];
    for(int i =0 ; i< 3; i++){
        A[i] = new string[3];
    }

    string str;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            cin>> str ;
            A[i][j] = str;

        }
    }

    for (int i = 0; i < 3; i++)
    {
            {
                cout<< A[i][1] << endl; // specfic second column
            }

    }

    int count=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {

            if(A[i][j] == "positive"){
                count++;
            }

        }
    }
    cout<< count;
    return 0;
}
