#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

bool prime[1000001];

void primecheck() {
	for (int i = 2; i <= 1000000; i++) prime[i] = 1;
	for (int i = 2; i*i <= 1000000; i++) {
		if (prime[i] == 0) continue;

		for (int j = 2 * i; j <= 1000000; j += i) {
			if (prime[j] == 0) continue;
			else prime[j] = 0;
		}
	}
	return;
}
int main() {
	FASTIO;
	primecheck();
	while (1) {
		int n;
		cin >> n;
		if (n==0) break;
		bool flag = true;
		for (int i = 2; i <= n/2; i++) {
			if (prime[i] == 1 && prime[n - i] == 1) {
				cout << n << " = " << i << " + " << n - i << "\n";
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}