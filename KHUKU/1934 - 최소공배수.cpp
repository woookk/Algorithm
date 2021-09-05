#include<iostream>
using namespace std;
int T, A, B;

int f(int num1, int num2) {
	int max;
	if (num1 >= num2)  max = num2;
	else max = num1;
	for (int i = max; i >= 1; i--) {
		if (num1 % i == 0 && num2 % i == 0)
			return i;
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A * B / f(A, B) << endl;
	}
	return 0;
}