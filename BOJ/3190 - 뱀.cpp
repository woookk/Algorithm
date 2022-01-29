#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int board[101][101];
char dir[10001];
int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int R, C;
		cin >> R >> C;
		board[R-1][C-1] = 1;
	}
	board[0][0] = -1;
	int L;
	cin >> L;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	int t = 0, idx = 0;
	for (int i = 0; i < L; i++) {
		int a; char b;
		cin >> a >> b;
		dir[a] = b;
	}
	while (1) {
		if (dir[t] == 'D') {
			idx = (idx + 1) % 4;
		}
		else if (dir[t] == 'L') {
			idx = (idx + 3) % 4;
		}
		t++;
		auto cur = q.back();
		int nx = cur.X + dx[idx];
		int ny = cur.Y + dy[idx];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
		if (board[nx][ny] == -1) break;
		else if (board[nx][ny] == 1) {
			board[nx][ny] = -1;
			q.push({ nx,ny });
		}
		else if (board[nx][ny] == 0) {
			board[nx][ny] = -1;
			q.push({ nx,ny });
			board[q.front().X][q.front().Y] = 0;
			q.pop();
		}
	}
	cout << t;
	return 0;
}