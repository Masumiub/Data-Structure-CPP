#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream file("input2.txt");

    ofstream fout;
    fout.open("output2.txt");
    if(!fout)
    {
        return EXIT_FAILURE;
        fout.close();
    }
    int words=0;int sum=0;
    if (file.is_open()) {
        string line;
        while (getline(file, line)){
            string s = line.c_str();
            int len=s.length();
            for(int i=0; s[i]!='\0'; i++){

                    if(s[i]=' '){
                    words++;
                    }
                    //sum += (s[i]- '0');

                }
                cout<< words;
            }
            //fout<<s<< endl;
        }

    else{
        cout<< "Unable to open file.";
    }
    system("cmd /c type output2.txt");
    file.close();

}
