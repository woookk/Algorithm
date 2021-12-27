#include<iostream>
#include<stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;

	int N;
	cin >> N;

	stack<pair <int ,int>> s;
	long long ans = 0;

	for (int i = 1; i <= N; i++) {
		int h;
		cin >> h;
		int cnt = 1;
		while (!s.empty() && s.top().first <= h) {
			ans += s.top().second;
			if (s.top().first == h) cnt += s.top().second; // 높이 h인 사람과 서로 볼 수 있는 개수 cnt
			s.pop();
		}
		if (!s.empty()) ans++;
		s.push({ h, cnt });
	}
	cout << ans;
	return 0;
}