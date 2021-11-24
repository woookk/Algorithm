#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	long long int A, B;
	cin >> A >> B;
	if (A > B) {
		long long int temp;
		temp = B;
		B = A;
		A = temp;
	}
	if (A == B) cout << 0;
	else {
		cout << B - A - 1 << "\n";
		for (long long int i = A + 1; i < B; i++) {
			cout << i << " ";
		}
	}
	return 0;
}

// for문에서 i도 long long int.