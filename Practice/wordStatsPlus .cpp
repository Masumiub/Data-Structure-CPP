#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void wordStatsPlus(string k) {
	ifstream file;
	file.open(k);
	if (!file) {
		cout << "Error, bad input file." << endl;
		return;
	}
	string x,p,s="";
	int line = 0;
	int length = 0,l,i=0, wods = 0;
	while (getline(file,x)) {
		line = line + 1;

		i = 0;
		int words = 0;
		while (x[i] != '\0') {
			while (x[i] != ' ' && x[i] != '\0')
			{
				p = p + x[i];
				i++;
			}
			if (p.length() != 0) {
				l = p.length();
				length = length + l;
                words++;
				p = "";
				i--;
			}
			i++;
		}
		wods = wods + words;
	    s=s.append(x);
	}
	int j = 0, q = 0, total = 0;
	for (int p = 0; p < s.length(); p++) {
		if (s[p] != ' ' && s[p]!='\0') {
			q = q + 1;
		}
	}
	int z = s.length();
	for (char i = 'a'; i <= 'z'; i++) {
		int l = 0;
		for (j = 0; j < z; j++) {
			if (i == s[j] || i == s[j] + 32) {
				l = 1;
			}
		}
		total = total + l;
	}
	cout <<"Total lines = " << line << endl;
	cout <<"Total words = "<<wods<<endl;
	cout << "Total unique letters = " << total << " ("<<(total*100)/26<<" % of alphabet)" << endl;
	cout << "Average words/line = " << (float)wods / line << endl;
	cout << "Average word length = " << (double)q / wods << endl;
}
int main() {
	ifstream file;
	wordStatsPlus("tobe.txt");
}
