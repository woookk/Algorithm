#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, limit = 1, mxcnt = 0;;
int board[101][101];
bool vis[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	FASTIO;
	cin >> N; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			limit = max(limit, board[i][j]);
		}
	}
	
	queue < pair<int, int>> q;
	while (limit>=0) {
		int cnt = 0;
		for (int i = 0; i < N; i++)
			fill(vis[i], vis[i] + N, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] <= limit || vis[i][j] != 0) continue;
				q.push({ i,j });
				cnt++;
				vis[i][j] = 1;
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (board[nx][ny] <= limit || vis[nx][ny] != 0) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				mxcnt = max(mxcnt, cnt);
				
			}
		}
		limit--;
	}
	cout << mxcnt;
	return 0;
}