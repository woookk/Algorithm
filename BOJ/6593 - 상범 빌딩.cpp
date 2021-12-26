#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

string board[31][31];
int dist[31][31][31];

int main() {
	FASTIO;
	while (1) {
		int L, R, C;
		cin >> L >> R >> C;
		if (!L && !R && !C) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < L; i++)
			for(int j=0; j<R; j++)
				fill(dist[i][j], dist[i][j] + C, 0);

		queue<tuple<int, int, int>> q;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if(board[i][j][k] == '.') dist[i][j][k] = -1;
					if (board[i][j][k] == 'E') dist[i][j][k] = -2;
					if (board[i][j][k] == 'S') {
						q.push({ i, j, k });
					}
				}
			}
		}
		bool flag = true;
		while (!q.empty() && flag) {
			auto cur = q.front();
			q.pop();
			int curX, curY, curZ;
			tie(curX, curY, curZ) = cur;
			for (int dir = 0; dir < 6; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];
				if (nx < 0 || nx >= L || ny < 0 || nz < 0 || ny >= R || nz >= C) continue;
				if (dist[nx][ny][nz] >= 0) continue;
				if (dist[nx][ny][nz] == -2) {
					flag = false;
					cout << "Escaped in " << dist[curX][curY][curZ] + 1 << " minute(s).\n";
					break;
				}
				dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
				q.push({ nx,ny,nz });
			}
		}
		if(flag)
			cout << "Trapped!\n";
	}
	return 0;
}