#include<iostream>
using namespace std;

int a, b, c, change;
int main() {
	cin >> a >> b >> c;
	if (b >= c) change = -1;
	else change = a/(c - b)+1;
	
	cout << change;
	return 0;
}