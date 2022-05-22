#include<iostream>
using namespace std;

void rev(char* str){
    if(*str =='\0'){
        return;
    }
    else{
        rev(str+1);
        cout<< *str;
    }
}

int main(){
    char* str = "musfique masum";
    rev(str);
    cout<< endl;
}
