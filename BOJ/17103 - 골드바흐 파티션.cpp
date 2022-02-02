#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

bool prime[1000001];

void primecheck() {
	for (int i = 2; i <= 1000000; i++) prime[i] = 1;

	for (int i = 2; i * i <= 1000000; i++) {
		if (prime[i] == 0) continue;

		for (int j = i * i; j <= 1000000; j += i) {
			if (prime[j] == 0) continue;
			else prime[j] = 0;
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	primecheck();
	while (T--) {
		int N;
		cin >> N;
		int cnt = 0;
		for (int i = 2; i <= N/2; i++) {
			if (prime[i] && prime[N - i]) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}