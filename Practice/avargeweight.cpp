#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(){


   ifstream file("input.txt");

    ofstream fout;
    fout.open("output.txt");
    if(!fout)
    {
        return EXIT_FAILURE;
        fout.close();
    }

    if (file.is_open()) {

        string str;int i=0;
        while(getline(file, str)){
            //cout<< str<< endl;
            string temp="";
            string temp2="";
    int sum=0;
            for (i= 0; str[i] != '\0'; i++)
            {
            if ((str[i] >= '0') && (str[i] <= '9'))
                {
            sum += (str[i] - '0');

                }
                else if((str[i] >= 'A') && (str[i] <= 'Z'))
                {

                    temp2 +=str[i];
                }
                else if ((str[i] >= 'a') && (str[i] <= 'z'))
                {
                    temp +=str[i];

                }

            }
            if(sum==1){
                    fout<< temp2;
                   fout<< temp<< " ";
                fout<< sum*100<< endl;
            }else{
                fout<< temp2;
                fout<< temp<< " ";
                if(sum*10<100)
                {fout<< (sum*10)/2<< endl;}
                else{
                    fout<< (sum*10)/4<< endl;
                }
            }
        }
fout<<"\nFigure: output.txt"<< endl;
    }
    else{
        cout<< "Unable to open file.";
    }
  system("cmd /c type output.txt");
     file.close();
}
