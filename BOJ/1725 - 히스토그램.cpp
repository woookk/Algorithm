#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int main() {
	FASTIO;
	int N;
	cin >> N;

	stack<pair<int, int>> s;
	int MX = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		int idx = i;
		while (!s.empty() && s.top().X >= tmp) {
			MX = max(s.top().X * (i - s.top().Y), MX);
			idx = s.top().Y;
			s.pop();
		}
		s.push({ tmp, idx });
	}
	while (!s.empty()) {
		MX = max(MX, s.top().X * (N-s.top().Y));
		s.pop();
	}
	cout << MX;
	return 0;
}