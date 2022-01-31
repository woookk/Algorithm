#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

bool prime[8000001];

void primecheck() {
	for (int i = 2; i <= 8000000; i++) {
		prime[i] = 1;
	}
	
	for (int i = 2; i <= 8000000; i++) {
		if (prime[i] == 0) continue;

		for (int j = 2 * i; j <= 8000000; j += i) {
			if (!prime[j]) continue;
			else prime[j] = 0;
		}
	}
}

int main() {
	FASTIO;
	int K;
	cin >> K;
	primecheck();
	int idx = 2;
	while (K) {
		if (prime[idx]) K--;
		if (K == 0) cout << idx;
		idx++;
	}
	return 0;
}