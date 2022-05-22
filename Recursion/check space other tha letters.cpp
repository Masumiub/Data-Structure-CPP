/*#include<iostream>
#include<string>
using namespace std;

bool check_str(string str){
    if(str.length()==0){
        return false;
    }
    else{
        for(int i=0; i<str.length(); i++){
            if(!(str[i]>='a' && str[i]<='z') && !(str[i]>='A' && str[i]<='Z')){
                return false;
            }
        }
        return true;
    }
}



int main()
{
    //char* str="musfiquem^asum";
    string str="musfiquem^asum";

    string str2="musfiquem^asum";
    //cout<< str+1;
    cout<< check_str(str2);
}
*/

/******************************************************************************
Take a name as input and check whether it contains other characters than letters and whitespaces
using recursion.
*******************************************************************************/

#include <iostream>

using namespace std;
int v = 0;
bool checking(string str)
{
    if(str[v] == '\0') return true;
    else if(!(  ((int)str[v] >= 97 && (int)str[v] <= 122) || ((int)str[v] >= 65 && (int)str[v] <= 90) || ((int)str[v] == 32)  )  )
        return false;
    else {
        v++;
        return checking(str);
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << str << endl;

    cout << checking(str);
}
