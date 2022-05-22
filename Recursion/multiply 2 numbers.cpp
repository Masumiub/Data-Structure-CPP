#include <bits/stdc++.h>
using namespace std;

int multiplyTwoInteger(int m, int n){
	if(n == 0){
		return 0;
	}
	return m + multiplyTwoInteger(m,n-1);
}

int main(){
	int m = 3, n =5;

	cout<<multiplyTwoInteger(m,n);

	return 0;
}
