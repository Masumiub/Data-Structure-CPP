#include <iostream>
using namespace std;

int compare(string str1, string str2, int i)
{

    if(i==str1.length())
    {
        return 0;
    }
    if(str1[i]>str2[i])
    {
        return 1;
    }
    if(str1[i]<str2[i])
    {
        return -1;
    }


    if(str1[i]==str2[i])
    {
       return compare(str1,str2,i+1);
    }



}

int main()
{
    string str1 = "hey";
    string str2 = "hey";
    cout<< compare(str1,str2,0);

    return 0;
}

