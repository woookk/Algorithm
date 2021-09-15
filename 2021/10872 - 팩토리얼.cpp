#include<iostream>
using namespace std;
int N, m=1;
int factorial(int N) {
	if (N <= 1);
	else {
		m *= N;
		factorial(N - 1);
	}
	return m;
}
int main() {
	cin >> N;
	cout << factorial(N);
	return 0;
}