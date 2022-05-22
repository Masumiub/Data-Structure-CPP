#include<iostream>
#include<fstream>

using namespace std;

int main() {
    std::ifstream file("thefile.txt");

     string x, y;//

    if (file.is_open()) {

        std::string line;
        int count = 0;

        while (std::getline(file, line)) {

            //count += 2;

            string s = line.c_str();

            int len=s.length();

            int n=len-1;

            string line_tmp;//

        for(int i=0; i<(len/2); i++){
            char temp= s[i];
            s[i]=s[n];
            s[n]=temp;
            n=n-1;
        }

        for(int i=0;s[i]!='\0';i++ ){ //
            if(count%2==0){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]+32;


            }
            }
            else if(count%2==1){
            if(s[i]>='a' && s[i]<='z'){
                s[i]=s[i]-32;

            }
            }
         }

             count++;
             cout << s << endl;
        }
        file.close();
        cout << "Lines - "<< count << endl;
    }

}

