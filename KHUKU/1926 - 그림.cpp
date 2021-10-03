#include<iostream>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool arr[501][501] = { 0 };
int maximum = 0, area;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void dfs(int x, int y) {
	arr[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i], Y = y + dy[i];
		if (X>=0 && X<=500 && Y>=0 && Y<=500)
			if (arr[X][Y]) {
				area += 1;
				dfs(X, Y);
			}
	}
	if (area > maximum) maximum = area;
}
int main() {
	FASTIO;
	int n, m, cnt=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				area = 1;
				dfs(i, j);
				cnt++;
			}
			else continue;
		}
	}
	if (cnt) cout << cnt << "\n" << maximum;

	else cout << cnt << "\n" << 0;
	
	return 0;
}