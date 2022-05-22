#include<iostream>
using namespace std;

string recursionMystery6(string s){
    if(s.length()==0){
        return s;
    }else if(s.length()%2==0){
        string rest = s.substr(0, s.length()-1);
        string last = s.substr(s.length()-1, 1);

        return last + recursionMystery6(rest);
    }
    else{
        string first = s.substr(0,1);
        string rest = s.substr(1);
        return "(" + first + ")" + recursionMystery6(rest);
    }

}

int main(){
cout<< recursionMystery6("computer");
return 0;
}
