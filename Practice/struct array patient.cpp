#include<iostream>
#include<string>

using namespace std;

struct patient{
    int pat_id;
    string pat_name;
    int pat_num;
};

int main(){
patient p[3]; // taken as normal array
//patient *p=new patient[3]; // taken as dynamic array
cout<< "Enter patient Details:"<< endl;
for(int i =0 ; i<3; i++){
    cout<< "Enter Patient ID: ";
    cin>> p[i].pat_id;
    cout<< "Enter Patient Name: ";
    cin>> p[i].pat_name;
    //getline(cin, p[i].pat_name);
    cout<< "Enter Patient Number: ";
    cin>> p[i].pat_num;
}
cout<< "Displaying all details: "<< endl;
        for(int i =0 ; i<3; i++){
        cout<< "Enter Patient ID: ";
        cout<< p[i].pat_id<< endl;
        cout<< "Enter Patient Name: ";
        cout<<  p[i].pat_name<< endl;
        cout<< "Enter Patient Number: ";
        cout<< p[i].pat_num<< endl;
        }


return 0;
}
