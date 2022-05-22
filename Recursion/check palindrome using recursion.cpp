#include<iostream>
#include<string>
using namespace std;

bool ispalin(string str, int low, int high){
    if(low>=high){
        return true;
    }
    if(str[low]!=str[high]){
        return false; // if the 1st & last letter mismatches
    }
    else{
        //move to next pair of letter
        return ispalin(str, low+1, high-1);
    }
}

int main(){
    string str = "babba";
    int len=str.length();

    if(ispalin(str, 0, len-1)){
        cout<< "Palindrome";
    }
    else{
        cout<< "Not Palindrome";
    }
    return 0;
}
