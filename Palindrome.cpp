//Palindrome
#include<iostream>
#include<string>
using namespace std;

bool palin(string str, int low_index, int high_index){

if(low_index >= high_index ){
        return true;
}

if(str[low_index] != str[high_index]){
        return false;
}

return palin(str, low_index+1, high_index-1);

}

int main(){

string word;
getline(cin, word);
//int slen= word.length();
if(palin(word, 0, word.length() - 1)){
    cout<< " True."<< endl;
}
else{
    cout<<" False "<< endl;
}

return 0;
}
