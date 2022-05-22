#include<iostream>
#include<list>
using namespace std;

struct student{
    string name;
    int roll;
    double marks;
};

int main(){
list<student> mylist;// student type er list
student s;
for(int i=1; i<=3; i++){

//s.name ="Rain";
cin>>s.name;
//s.roll =1;
cin>> s.roll;
//s.marks = 20;
cin>> s.marks;
mylist.push_back(s);
}
//cout<< mylist.size()<< endl;
/*
for(list<student>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){

    cout<< it->name<< endl;
}*/

for(list<student>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){

    if(it->roll==2){
        //cout<< "delete";
        mylist.erase(it);
        break;
    }
}


for(list<student>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){

    cout<< it->name<< endl;
    cout<< it->roll<< endl;
}

}


