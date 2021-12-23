#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };
int box[101][101][101];
int dist[101][101][101];

int M, N, H;

int main(void) {
	FASTIO;
	cin >> M >> N >> H;
	queue<tuple<int, int, int>> q;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) q.push({ i, j, k });
				if (box[i][j][k] == 0) dist[i][j][k] = -1;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || nx >= H || ny < 0 || ny >= N || nz < 0 || nz >= M) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			q.push({ nx, ny, nz });
		}
	}
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
	return 0;
}