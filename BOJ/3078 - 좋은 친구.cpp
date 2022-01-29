#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	string tmp;
	long long ans = 0;
	queue<int> q[21];
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		int len = tmp.length();
		while (!q[len].empty() && i - q[len].front() > K) {
			q[len].pop();
		}
		ans += q[len].size();
		q[len].push(i);
	}
	cout << ans;
	return 0;
}