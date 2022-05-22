#include<iostream>
#include<fstream>

using namespace std;


string rev(string s) {
    string temp = "";
    int k = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        temp += s[i];
    }
    return temp;
}

void swap(string &s1, string &s2) {
    string temp = s1;
    s1 = s2;
    s2 = temp;
}

int main() {
    std::ifstream file("thefile.txt");
    if (file.is_open()) {

        string line1, line2;
        int count = 0;

        string temp1, temp2;

        while (std::getline(file, line1) && std::getline(file, line2)) {
            count += 2;

            line1 = rev(line1);
            line2 = rev(line2);
            swap(line1, line2);

            cout << line1 << endl;
            cout << line2 << endl;
        }

        file.close();
        cout << "Lines - "<< count << endl;
    }
}
