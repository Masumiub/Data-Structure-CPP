#include<iostream>
#include<fstream>
using namespace std;

void flipLines(string filename){
ifstream fin;

int lines=0;
    fin.open(filename.c_str());
    if(!fin)
    {
        cout<< "Unable to open input file "<< filename<<"!"<< endl;
        fin.close();
    }
string out_edited_file = "edited_file.txt";

ofstream fout;
    fout.open(out_edited_file.c_str());
    if(!fout)
    {
        cout<< "Unable to open input file "<< filename<<"!"<< endl;
        fout.close();
    }
    int i=0;
  string temp1, temp2;

  int len;  int len2;

  int count=0;
    while(getline(fin, temp1)&& getline(fin, temp2))
{

         for(i=0;temp1[i]!='\0';i++ ){
            if(temp1[i]>='A' && temp1[i]<='Z'){
                temp1[i]=temp1[i]+32;
            }

         }
        len=temp1.length();
        int n=len-1;
        for(i=0; i<(len/2); i++){
            char temp= temp1[i];
            temp1[i]=temp1[n];
            temp1[n]=temp;
            n=n-1;
        }

         for(i=0;temp2[i]!='\0';i++ ){
            if(temp2[i]>='a' && temp2[i]<='z'){
                temp2[i]=temp2[i]-32;
            }

         }
         len2=temp2.length();
         int n2=len2-1;
        for(i=0; i<(len2/2); i++){
            char temp3= temp2[i];
            temp2[i]=temp2[n2];
            temp2[n2]=temp3;
            n2=n2-1;
        }

            fout << temp2 << endl;

            fout << temp1 << endl;

}
std::ifstream file("edited_file.txt");
if (file.is_open()) {

        std::string line;
        while (std::getline(file, line)) {
        count++;
        string s = line.c_str();
 }


cout<< count<< endl;
system("cmd /c type edited_file.txt");

}
}

int main()
{
    string filename = "carroll.txt";
    string out_edited_file = "edited_file.txt";

    flipLines(filename);

    return 0;
}
