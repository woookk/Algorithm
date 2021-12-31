#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = 0; j < 2 * (N - i) - 1; j++)
			cout << "*";
		cout << "\n";
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = 0; j < 2 * (N - i) - 1; j++)
			cout << "*";
		cout << "\n";
	}
	return 0;
}