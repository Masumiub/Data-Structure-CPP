#include<iostream>
using namespace std;

int size =5;
int get_max(int arr[]){
    static int i, max=-999999;
    if(i<size){
        if(max<arr[i]){
            max = arr[i];
        }
        i++;
        get_max(arr);
    }
    return max;
}

int get_min(int arr[]){
    static int i, min=999999;
    if(i<size){
        if(min>arr[i]){
            min = arr[i];
        }
        i++;
        get_min(arr);
    }
    return min;
}

int counting_less_than(int arr[]){
    static int i, count = 0;
    if(i<size){
        if(i<3){
            count++;
        }
        i++;
        return counting_less_than(arr);
    }
    return count;
}


int size2 = 8;
void display(int arr2[]){
    static int i;
    if(i<size2){
        cout<< arr2[i]<< "->";
        i++;
        display(arr2);
    }
}

int count_unique(int arr2[]){
    static int i, count=0;
    if(i<size2){
        if(arr2[i]!=arr2[i+1]){
            count++;
        }
        i++;
        count_unique(arr2);
    }
    return count;
}

bool isprime(int n, int i)
{
    if(i==1) {
        return true;
    }
    if(n%i==0) {
        return false;
    }

    return isprime(n,i-1);
}

bool isodd(int n){
    if(n%2==1){
        return true;
    }
    return false;
}

int summation_odd(int arr[]){
    static int i, sum=0;
    if(i<size){
        if(arr[i]>1){
        if(isprime(arr[i],arr[i]/2)){
        //if(arr[i]%2==1){
            sum +=arr[i];
        }
        }
        i++;
        summation_odd(arr);
    }
    return sum;
}
int main(){
    int arr[5] = {0, 3, 3, 7, 5};
    cout<<"The maximum value in array:" <<get_max(arr)<< endl;
    cout<<"The minimum value in array:" <<get_min(arr)<< endl;
    cout<< "The Sum of odd numbers: "<< summation_odd(arr)<< endl;
    //cout<< arr[1]/2<< endl;
    cout<< endl;
    cout<< "Num of values less than 3 : "<< counting_less_than(arr)-1;
    cout<< endl;
    int arr2[8] = {0,0,1,2,3,3,3,5};
    display(arr2);
    cout<< endl;
    cout<< "The Unique Nums:"<< count_unique(arr2);



    return 0;
}
