#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

string board[101];
int dist[101][101];
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
			cin >> board[i];
	}

	for (int i = 0; i < N; i++) fill(dist[i], dist[i] + M, -1);
			queue<pair<int, int>> q;
			dist[0][0] = 0;
			q.push({ 0, 0 });
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					q.push({ nx, ny });
				}
			}
	cout << dist[N - 1][M - 1] + 1;
	return 0;
}