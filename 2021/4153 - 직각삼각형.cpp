#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int A, B, C;
	int a, b, c;
	while (cin >> A >> B >> C) {
		if (A + B + C == 0) break;
		a = pow(A, 2), b = pow(B, 2), c = pow(C, 2);
		if (a == b + c || b == c + a || c == a + b) cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}