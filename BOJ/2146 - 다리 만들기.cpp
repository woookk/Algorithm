#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, cnt = 0, MN = 10000;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool board[101][101];
int vis[101][101];
int dist[101][101];

void Numbering(int i, int j, int cnt) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	vis[i][j] = cnt;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (board[nx][ny] == 0 || vis[nx][ny] > 0) continue;
			vis[nx][ny] = cnt;
			q.push({ nx,ny });
		}
	}
}

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (dist[nx][ny] > 0 || vis[i][j] == vis[nx][ny]) continue;
			if (vis[nx][ny] != 0 && vis[i][j] != vis[nx][ny]) {
				MN = min(MN, dist[cur.X][cur.Y]);
				while (!q.empty()) q.pop();
				return;
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
	for (int i = 0; i < N; i++) fill(dist[i], dist[i] + N, 0);
}

int main() {
	FASTIO;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || board[i][j] == 0) continue;
			cnt++;
			Numbering(i, j, cnt);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] != 0) {
				BFS(i, j);
			}
		}
	}
	cout << MN;
	return 0;
}