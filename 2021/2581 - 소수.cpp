#include<iostream>
using namespace std;
int sum = 0, cnt = 0, m = 10000;
bool arr[10001] = { 0 };
void prime(int n) {
	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == false) continue;
		for (int j = 2 * i; j <= n; j += i) {
			if (arr[j] == false) continue;
			else arr[j] = false;
		}
	}
}
int main() {
	int M, N;
	cin >> M >> N;
	prime(N);
	for (int i = M; i <= N; i++) {
		if (arr[i]) {
			sum += i;
			cnt++;
			if (m > i) m = i;
		}
	}

	if (cnt == 0) cout << -1;
	else cout << sum << "\n" << m;
	return 0;
}