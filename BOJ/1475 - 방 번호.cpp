#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N, cnt[10] = {}, ans = 1;
	cin >> N;

	while (N) {
		cnt[N % 10]++;
		N /= 10;
	}

	for (int i = 0; i < 9; i++) {
		if (i != 6) ans = max(ans, cnt[i]);
	}
	ans = max(ans, (cnt[6] + cnt[9] + 1) / 2);
	cout << ans;
	return 0;
}