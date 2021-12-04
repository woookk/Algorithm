#include<iostream>
#include<queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M, cnt = 0;
		cin >> N >> M;
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			q.push({ i, temp });
		}
		while (!q.empty()) {
			int temp;
			bool flag = false;
			temp = q.front().second;
			for (int i = 0; i < (int)q.size(); i++) {
				if (q.front().second > temp) {
					flag = true;
					break;
				}
				else {
					q.push({ q.front().first, q.front().second });
					q.pop();
				}
			}
			if (flag) {
				continue;
			}
			else {
				if (q.front().first == M) {
					cnt++;
					break;
				}
				cnt++;
				q.pop();
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}