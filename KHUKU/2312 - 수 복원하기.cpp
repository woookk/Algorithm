#include<iostream>
#include<cstring>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool arr[100001] = { 0 };
int factor[100001];
void prime(int num) {
	for (int i = 2; i <= num; i++) arr[i] = true;
	for (int i = 2; i <= num; i++) {
		if (arr[i]) continue;
		for (int j = 2 * i; j <= num; j = j + i) {
			if (arr[j]) continue;
			else arr[j] = false;
		}
	}
}

int main() {
	FASTIO;
	int T, N, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		n = N;
		memset(factor, 0, sizeof(factor));
		prime(N);
		int j = 2;
		while(n-1) {
			if (arr[j] && n % j == 0) {
				n /= j;
				factor[j]++;
			}
			else j++;
		}
		for (int k = 2; k <= N; k++) {
			if (factor[k] != 0) cout << k << " " << factor[k] << "\n";
		}
	}
	return 0;
}