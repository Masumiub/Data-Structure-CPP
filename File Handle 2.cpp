#include<iostream>
#include<fstream>
using namespace std;
int main(){
char arr[100];
cout<< "Enter your name and Age";
cin.getline(arr,100);

ofstream myfile("xyz.txt", ios::out|ios::app);// append mode, + output mode
//myfile.open("xyz.txt");
myfile<<arr;
myfile.close();
cout<< "File write operation performed successfully"<< endl;

cout<< "Reading from file Operation started"<< endl;
char arr1[100];
ifstream obj("xyz.txt");// taking input from the file
obj.getline(arr1,100);
cout<< "Array Content"<< arr1<< endl;
cout<< "File Read Operation Completed"<< endl;
obj.close();

}
