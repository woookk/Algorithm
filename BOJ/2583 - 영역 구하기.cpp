#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };
int M, N, K;

int board[101][101];
bool vis[101][101];

int main() {
	FASTIO;
	cin >> M >> N >> K;
	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				board[j][k] = 1;
			}
		}
	}
	
	int cnt = 0;
	vector<int> ans;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 || vis[i][j] == 1) continue;
			queue<pair<int, int>> q;
			vis[i][j] = 1;
			q.push({ i, j });
			int area = 1;
			cnt++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
					if (vis[nx][ny] == 1) continue;
					if (board[nx][ny] != board[cur.X][cur.Y]) continue;
					vis[nx][ny] = 1;
					q.push({ nx, ny });
					area++;
				}
			}
			ans.push_back(area);
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}