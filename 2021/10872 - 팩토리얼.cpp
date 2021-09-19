#include<iostream>
using namespace std;
int N, m=1;
int factorial(int n) {
	if (n <= 1);
	else {
		m *= n;
		factorial(n - 1);
	}
	return m;
}
int main() {
	cin >> N;
	cout << factorial(N);
	return 0;
}