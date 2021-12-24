#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int T;
string board[1001];
int dist1[1001][1001];
int dist2[1001][1001];


int main() {
	FASTIO;
	cin >> T;
	while (T--) {
		int w, h;
		bool flag = true;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> board[i];
		}
		for (int i = 0; i < h; i++) {
			fill(dist1[i], dist1[i] + w, -1);
			fill(dist2[i], dist2[i] + w, -1);
		}
		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					q1.push({ i, j });
					dist1[i][j] = 0;
				}
				if (board[i][j] == '@') {
					q2.push({ i, j });
					dist2[i][j] = 0;
				}
			}
		}
		while (!q1.empty()) {
			auto cur = q1.front();
			q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
				q1.push({ nx,ny });
			}
		}
		while (!q2.empty() && flag) {
			auto cur = q2.front();
			q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
					cout << dist2[cur.X][cur.Y] + 1 << "\n";
					flag = false;
					break;
				}
				if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
				q2.push({ nx,ny });
			}
		}
		if(flag)
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}