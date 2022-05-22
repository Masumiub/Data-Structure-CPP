#include<iostream>
#include<sstream>
using namespace std;
void extract(string str)
{
    stringstream ss;
    //storing the whole string into string stream
    ss<< str;
    //running loop till the end of the stream
    string tmp;
    int found;
    while(!ss.eof()){
        //extracting word by word from stream
        ss>> tmp;
        //checking the given word is integer or not.
        if(stringstream(tmp)>> found){
            cout<< found<< " ";
        }
        // to save from space at the end of string
        tmp="";
    }
}
int main(){
string str="Food 12 Food 24";
extract(str);
return 0;
}
