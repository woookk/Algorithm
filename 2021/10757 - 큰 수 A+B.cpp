#include<iostream>
#include<string>
using namespace std;
string A, B, C;
int up = 0;
string reverse(string A) {
	string a=A;
	for (int i = 0; i < A.length(); i++)
		a[i]= A[A.length() - 1 - i];
	return a;
}
string add(string A, string B) {
	string sum;
	int x = 0, y = 0;
	for (int i = 0; i < B.length(); i++) {
		x = A[i] - '0'; y = B[i] - '0';
		sum += to_string((x + y + up) % 10);
		if (x + y + up >= 10) {
			up = 1;
		}
		else up = 0;
	}
	for (int i = B.length(); i < A.length(); i++) {
		x = A[i] - '0';
		sum += to_string((x + up)%10);
		if (x + up >= 10) {
			up = 1;
		}
		else up = 0;
	}
	return sum;
}
int main() {
	cin >> A >> B;
	if (A.length() < B.length()) {
		C = A;
		A = B;
		B = C;
	}
	A=reverse(A); B=reverse(B);
	string sum;
	sum= add(A, B);
	if (up)
		sum += '1';
	cout << reverse(sum);
	return 0;
}