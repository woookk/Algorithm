#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board[26];
int vis[26][26];

int main() {
	FASTIO;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	vector<int> ans;
	int cnt = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '0' || vis[i][j] == 1) continue;
			
			vis[i][j] = 1;
			q.push({ i, j });
			cnt++;
			int area = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
					vis[nx][ny] = 1;
					area++;
					q.push({ nx, ny });
				}
			}
			ans.push_back(area);
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}