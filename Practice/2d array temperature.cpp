#include <iostream>
using namespace std;

int main(){
    int temp[11] = {1,19, 20, 12, 30, 11, 15, 25, 35, 13, -5};
    for(int i =0 ; i<=10; i++){
        cout<< temp[i]<<" ";
    }

    int **A = new int*[3];
    for(int i =0 ; i< 3; i++){
        A[i] = new int[11];
    }

    int count1=0;
    int count2=0;
    int count3=0;
    for(int i =0 ; i<=10; i++){
        if(temp[i]<=10){
            A[0][i]=temp[i];
            count1++;
        }
        else if(temp[i]>10 && temp[i]<20){
            A[1][i]=temp[i];
            count2++;
        }
        else{
            A[2][i]=temp[i];
            count3++;
        }
    }

cout << endl;
cout << endl;
cout << endl;
    for(int  i =0 ; i<3; i++){
        for(int j =0; j<11; j++){
            if(A[i][j]==0){
                cout<< "";
            }
            else if( A[i][j]>100000){
                cout<< "";
            }
            else{
            cout<< A[i][j]<< " ";
            }
        }
        cout << endl;
    }


return 0;
}
