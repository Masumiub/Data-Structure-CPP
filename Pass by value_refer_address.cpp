#include<iostream>
using namespace std;
void myswap(int* &m, int* &n) { //pass by reference
	int* p;
	p = m;
	m = n;
	n = p;
	cout << m << endl;
	cout << n << endl;
}
void myswap1(int** m, int** n) { //pass by address
	int *p;
	p = *m;
	*m = *n;
	*n = p;

}
void myswap2(int *p, int *q) {
	int* temp;
	temp = p;
	p = q;
	q = temp;
	cout << p << endl;
	cout << q << endl;
}
int main() {
	int a = 5, b = 6;
	int* p = &a;
	int* q = &b;

	cout << "Before operation: " << endl;
	cout << p << endl;
	cout << q << endl;

	cout << "Pass by reference: " << endl;
	myswap(p, q);


	cout << "Pass by address: " << endl;
	myswap1(&p, &q);
	cout << p << endl;
	cout << q << endl;


	cout << "Pass by  value:" << endl;
	myswap2(p, q);
}
