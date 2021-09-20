#include<iostream>
#include<cmath>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool num[3200] = { 0 };
void prime(int N) {
	for (int i = 2; i <= sqrt(N); i++) {
		num[i] = 1;
	}
	for (int i = 2; i <= sqrt(N); i++) {
		if (num[i] == 0) continue;
		for (int j = i * 2; j <= sqrt(N); j += i) {
			if (num[j] == 0) continue;
			else num[j] = 0;
		}
	}

}
int main() {
	FASTIO;
	int N, n, i = 2;
	cin >> N;
	prime(N);
	n=sqrt(N);
	while (N - 1 && i<=n) {
		if (N % i == 0) {
			N /= i;
			cout << i << "\n";
		}
		else i++;
	}
	if (i > n && N!=1) cout << N;
	return 0;
}