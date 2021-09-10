#include<iostream>
using namespace std;

int main() {
	int X, i;
	cin >> X;
	
	for (i = 1; i<5000; i++) {
		if (X <= i * (i + 1) / 2) break;
	}
	if (i * (i + 1) / 2 == X) {
		if (i % 2 == 0) X = i;
		else X = 1;
	}
	else {
		X -= i * (i - 1) / 2;
		if (i % 2 == 0);
		else X = i+1 - X;
	}
	cout << X << '/' << i-X+1;
	return 0;
}