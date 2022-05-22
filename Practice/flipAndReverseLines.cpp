#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int flipAndReverseLines() {
	int even_line_count=0;
	int odd_line_count=0;
	int total_count=0;


	ifstream file;
	cout<< "Input file name?";
	string n;
	getline(cin,n);


	file.open(n);
	if (!file) {
		//cout << "\"\"" << endl;
		cout<<"Unable to open that file.  Try again."<<endl;
		//return;
	}
	string temp1, temp2;
    string x,y,p;
    while(getline(file, x)&& getline(file, y))
    {

    int i = 0;
		p = x;
			while (y[i] != '\0') {
				if (y[i] >= 'a' && y[i] <= 'z') {
					y[i] = y[i] - 32;even_line_count++;
				}
				i++;
			}
		 i = 0;
		while (x[i] != '\0') {
			if (x[i] >= 'A' && x[i] <= 'Z') {
				x[i] = x[i] + 32;
			}
			i++;

		}

		cout << y << endl;
		cout << x << endl;


     }

	return even_line_count;
}


int main(){
cout<<flipAndReverseLines();
}
