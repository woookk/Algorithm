#include<iostream>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int arr[301][301] = { 0 };
bool chk[301][301] = { 0 };
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

void cal(int x, int y) {
	int sur = 0;
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i], Y = y + dy[i];
			if (chk[X][Y]==0) sur++;
	}
	if (sur > arr[x][y]) arr[x][y] = 0;
	else arr[x][y] -= sur;
}

void dfs(int x, int y) {
	chk[x][y] = 0;
	
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i], Y = y + dy[i];
			if (chk[X][Y])
				dfs(X, Y);
	}
}

int main() {
	FASTIO;
	int n, m, cnt=0, year = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j]>0) chk[i][j] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > 0) cal(i, j);
				else continue;
			}
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (chk[i][j]) {
					dfs(i, j);
					cnt += 1;
				}
				else continue;
			}
		}
		if (cnt != 1) break;

		year++;
	}
	if (cnt == 0) cout << 0;
	else cout << year << "\n";

	return 0;
}