#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1="123";
    string s2="456";

    cout<< "ASCII Values of s1: "<< endl;
    for(int i=0; s1[i]!='\0'; i++){ // 123
        cout<< int(s1[i])<< endl;
    }

    cout<< endl;
    cout<< "ASCII Values of s2: "<< endl;

    for(int i=0; s2[i]!='\0'; i++){ // 456
        cout<< int(s2[i])<< endl;
    }

    /*
    char c1='A';
    cout<<"Ascii Value of A:"<< int(c1)<< endl;
    char c2='Z';
    cout<<"Ascii Value of Z:"<< int(c2);

    if(c1>c2){
        cout<< "true";
    }
    else{
        cout<< "false";
    }

    if(s2>s1){
        cout<< "true";
    }
    else{
        cout<< "false";
    }*/

    return 0;
}

