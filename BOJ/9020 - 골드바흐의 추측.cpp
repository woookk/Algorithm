#include<iostream>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool prime[10001];

void primecheck() {
	for (int i = 2; i <= 10000; i++) prime[i] = 1;
	for (int i = 2; i * i <= 10000; i++) {
		if (prime[i] == 0) continue;
		for (int j = i * i; j <= 10000; j += i) {
			if (prime[j] == 0) continue;
			else prime[j] = 0;
		}
	}
}
int main() {
	FASTIO;
	int T, n, a, b;
	cin >> T;
	primecheck();
	while(T--) {
		cin >> n;
		for (int j = 2; j <= n/2; j++) {
			if (prime[j] && prime[n - j]) {
				a = j, b = n - j;
			}
		}
		cout << a << ' ' << b << "\n";
	}
	return 0;
}