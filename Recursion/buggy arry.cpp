#include<iostream>
using namespace std;

int size = 6;
int check_five(int arr[], int index, int max_count, int counter){
    if(index == size-1){
        return max_count;
    }
    if(arr[index] == 5){
        //cout<<arr[index];
        counter++;
        //return counter;
    }
    /*else{
        counter = 0;
    }*/
    if(max_count<counter){
        max_count = counter;
        return max_count;
    }
    index++;
    check_five(arr, index, max_count, counter);

}

int main(){
    int arr[size] = {1,5,5,6,5,7};
    cout<< check_five(arr,0, -200000, 0);

    return 0;
}
