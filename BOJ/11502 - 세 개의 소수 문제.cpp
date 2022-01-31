#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

bool prime[1001];

void primecheck() {
	for (int i = 2; i <= 1000; i++) prime[i] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (prime[i] == 0) continue;

		for (int j = 2 * i; j <= 1000; j += i) {
			if (prime[j] == 0) continue;
			else prime[j] = 0;
		}
	}
	return;
}

void search(int K) {
	for (int i = 2; i < K; i++) {
		for (int j = 2; j < K; j++) {
			for (int k = 2; k < K; k++) {
				if (prime[i] && prime[j] && prime[k] && i + j + k == K) {
					cout << i << " " << j << " " << k << "\n";
					return;
				}
			}
		}
	}
	cout << 0 << "\n";
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	primecheck();
	while (T--) {
		int K;
		cin >> K;
		search(K);
	}
	return 0;
}