#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N, K, room[6][2] = {}, ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		room[b-1][a]++;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			ans += (room[i][j] + K-1) / K;
		}
	}
	cout << ans;
	return 0;
}