#include<iostream>
using namespace std;
bool fun(string str, int start_index, int end_index){
    if(start_index>=end_index){
        return true;
    }
    if(str[start_index]!=str[end_index]){
        return false;
    }else{
        return fun(str, start_index+1, end_index-1);
    }

}

int main(){
    string str = "obba";
    cout<< fun(str,0,str.length()-1)<< endl;
    return 0;
}
