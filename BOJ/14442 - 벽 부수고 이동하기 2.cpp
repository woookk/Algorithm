#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string board[1001];
int dist[11][1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0});
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int curX, curY, cnt;
		tie(curX, curY, cnt) = q.front();
		q.pop();
		if (cnt < K) {
			for (int dir = 0; dir < 4; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (dist[cnt+1][nx][ny] > 0) continue;
				dist[cnt + 1][nx][ny] = dist[cnt][curX][curY] + 1;
				q.push({ nx, ny, cnt + 1 });
			}
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (board[nx][ny] == '1' || dist[cnt][nx][ny] > 0) continue;
			dist[cnt][nx][ny] = dist[cnt][curX][curY] + 1;
			q.push({ nx, ny, cnt });
		}
	}
	int MX = 1000000;
	for (int i = 0; i < K+1; i++) {
		if(dist[i][N - 1][M - 1]>0) MX = min(MX, dist[i][N - 1][M - 1]);
	}
	if (MX == 1000000) MX = -1;
	cout << MX;
	return 0;
}