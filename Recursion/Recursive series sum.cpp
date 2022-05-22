#include <iostream>
using namespace std;

int recur_sum(int start, int end){
    if(start  == end){
        return start;
    }else{
        return start + recur_sum(start+1, end);
    }
}

int main()
{
    int start =0, end =100;
    cout<< recur_sum(0,100);
    return 0;
}
