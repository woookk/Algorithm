#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int n, w, L;
	cin >> n >> w >> L;
	queue<int> q;
	int t = 0, weight = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		while (1) {
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}
			if (weight + tmp <= L) break;
			q.push(0);
			t++;
		}
		q.push(tmp);
		weight += tmp;
		t++;
	}
	cout << t + w;
	return 0;
}