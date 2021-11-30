#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		stack<pair<int, int>> s;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int h; 
			cin >> h;
			int idx = i;
			while (!s.empty() && s.top().first >= h) {
				ans = max(ans, 1LL * (i - s.top().second) * s.top().first);
				idx = s.top().second; // idx를 stack에 쌓여있는 가장 먼 idx로 바꿈.
				s.pop();
			}
			s.push({h, idx });
		}
		while (!s.empty()) {
			ans = max(ans, 1LL * (n - s.top().second) * s.top().first);
			s.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}