#include<iostream>
#include<fstream>
using namespace std;
int main(){
ofstream masumfile;
masumfile.open("tuna.txt");
masumfile<< "Hello Cpp";
masumfile.close();
return 0;
}
