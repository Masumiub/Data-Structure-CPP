#include<iostream>
#include<fstream>
using namespace std;
int main() {

    std::ifstream file("thefile.txt");
    string line1, line2;
    int count = 0;

    if (file.is_open()) {
        while (std::getline(file, line1) && std::getline(file, line2)) {
            count += 2;
            string s = line1.c_str();

            line1 = "";
            int k = 0;
            for(int i = line1.size() - 1; i >= 0; i--) {
            line1 += s[i];
            }

            string s2 = line2.c_str();
            line2 = "";
            for(int i = line2.size() - 1; i >= 0; i--) {
            line2 += s2[i];
            }

            string temp = line1;
            line1 = line2;
            line2 = temp;

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


             cout << line1 << endl;
            cout << line2 << endl;
        }
        file.close();
        cout << "Lines - "<< count << endl;
    }

}

