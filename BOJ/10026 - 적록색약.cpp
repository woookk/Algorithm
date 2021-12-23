#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board1[101], board2[101]; // char board[101][101]로도 가능
bool vis1[101][101]; 
bool vis2[101][101];
int N, cnt1 = 0, cnt2 = 0;

int main() {
	FASTIO;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board1[i];
		board2[i] = board1[i];
	}
	queue<pair<int, int>> q1 ,q2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board2[i][j] == 'G')
				board2[i][j] = 'R';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis1[i][j] != 1) {
				q1.push({ i, j });
				cnt1++;
			}
			if (vis2[i][j] != 1) {
				q2.push({ i, j });
				cnt2++;
			}
			while (!q1.empty()) {
				pair<int, int> cur1 = q1.front();
				q1.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur1.X + dx[dir];
					int ny = cur1.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (board1[cur1.X][cur1.Y] != board1[nx][ny] || vis1[nx][ny] != 0) continue;
					vis1[nx][ny] = 1;
					q1.push({ nx, ny });
				}
			}
			while (!q2.empty()) {
				pair<int, int> cur2 = q2.front();
				q2.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur2.X + dx[dir];
					int ny = cur2.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (board2[cur2.X][cur2.Y] != board2[nx][ny] || vis2[nx][ny] != 0) continue;
					vis2[nx][ny] = 1;
					q2.push({ nx, ny });
				}
			}
		}
	}
	cout << cnt1 << " " << cnt2;
	return 0;
}

// G를 R로 먼저 다 바꿔준 후에 BFS 알고리즘 돌려야함.
// 모든 배열 2개씩 선언하지 말고, fill 함수를 통해 초기화 후 하는게 깔끔, 메모리 적게 듬.
/*
char board[101][101];

가독성을 위해 함수 정의해서 사용. bfs, area
void bfs(int i, int j) {
  queue<pair<int, int>> Q;
  Q.push({ i,j });
  vis[i][j] = 1;
  while (!Q.empty()) {
	auto cur = Q.front(); Q.pop();
	for (int dir = 0; dir < 4; dir++) {
	  int nx = cur.X + dx[dir];
	  int ny = cur.Y + dy[dir];
	  if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
	  if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
	  vis[nx][ny] = 1;
	  Q.push({ nx,ny });
	}
  }
}

int area(){
  int cnt = 0;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if (!vis[i][j]) {
		cnt++;
		bfs(i, j);
	  }
	}
  }
  return cnt;
}

  // 적록색약인 사람을 구하기위한 방문배열 초기화
  for(int i = 0; i < n; i++)
	fill(vis[i], vis[i]+n, false);

*/