#include<iostream>
using namespace std;

struct student{
    string name;
    int roll;
    double gpa;

    void display(){
        cout<< "Welcome"<< endl;
    }
};

int main(){

int i;
student s;
s.name ="masum";
//cout<< s.name<< endl;
s.roll =22;
cout<< s.roll<< endl;
s.display();

int *p =&i;

student *sp = new student;

sp->name= "musfique";
cout<< sp->name<< endl;

student *arr = new student[3];
arr[0].name = "Tipu"  ;  // behave like variable(use dot operation here)
cout<< arr[0].name<< endl;


return 0;
}
