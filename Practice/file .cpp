#include<iostream>
#include<fstream>

using namespace std;

int main() {
    std::ifstream file("thefile.txt");
    if (file.is_open()) {
        std::string line;
        int count = 0;
        while (std::getline(file, line)) {
            count++;
            printf("%s\n", line.c_str());
        }
        file.close();
        cout << "Lines - "<< count << endl;
    }
}
