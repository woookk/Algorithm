#include<iostream>
using namespace std;
int gcd(int a, int b) {
	int r = a % b;

	if (r == 0) return b;
	else return gcd(b, r);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << "\n" << a*b/gcd(a,b);
	return 0;
}