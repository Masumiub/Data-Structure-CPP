#include<iostream>
using namespace std;

int main()
{
   string x,p="";

getline(cin,x);
int i=0,m=0;


while(x[i]!='\0'){
    while(x[i]!=' ' && x[i]!='\0')
{
    p=p+x[i];

    i++;

}
if(p.length()!=0){
    m++;
    p="";
    i--;
}
i++;
}
cout<<m<<endl;
}
