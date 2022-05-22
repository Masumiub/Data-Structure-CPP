#include<iostream>
#include<string>
using namespace std;

int main(){
string str;
cout<< "Enter a string: ";

getline(cin, str);
int len=str.length();
cout<<"String Length: " <<len<< endl;

int count_vowel=0;
int count_consonants=0;

for(int i=0; i<len; i++){
    if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='i' || str[i]=='I' || str[i]=='o' || str[i]=='O' || str[i]=='u' || str[i]=='U'){
        count_vowel++;
    }
    else{
        count_consonants++;
    }
}

cout<<"Number of Vowels: "<<  count_vowel<< endl;
cout<< "Number of Consonants: "<<count_consonants<< endl;

char *vowel_arr = new char[count_vowel];
char  *consonants_arr = new char[count_consonants];

int j=0,k=0;
for(int i=0; i<len; i++){
    if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='i' || str[i]=='I' || str[i]=='o' || str[i]=='O' || str[i]=='u' || str[i]=='U'){
        vowel_arr[j] = str[i];
        j++;
    }
    else{
        consonants_arr[k] = str[i];
        k++;
    }
}
cout<< "Vowels in this Strings: "<< endl;
for(int i=0; i<j; i++){
    cout<< vowel_arr[i]<< " ";
}

cout<< "\nConsonants in this Strings: "<< endl;
for(int i=0; i<k; i++){
    cout<< consonants_arr[i]<< " ";
}
    return 0;
}
