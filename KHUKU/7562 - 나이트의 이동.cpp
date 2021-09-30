#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
queue<pair<int, int>> q;
int xi, yi, xf, yf, l;
int check[301][301] = { 0 };
int dx[8] = { 1, 1, 2, 2, -1, -1, -2 ,-2 };
int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };
int BFS() {
	while (!q.empty()) {
		pair<int, int> cor = q.front();
		q.pop();
		if (cor.first == xf && cor.second == yf) return check[xf][yf];
		for (int i = 0; i < 8; i++) {
			if (!(cor.first + dx[i] < l && cor.second + dy[i] < l && cor.first + dx[i] >= 0 && cor.second + dy[i] >= 0)) continue;

			if (check[cor.first + dx[i]][cor.second + dy[i]] == 0) {
				check[cor.first + dx[i]][cor.second + dy[i]] = check[cor.first][cor.second] + 1;
				q.push({ cor.first + dx[i], cor.second + dy[i] });
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> l;
		cin >> xi >> yi >> xf >> yf;
		while(!q.empty()) q.pop();
		q.push(make_pair(xi,yi));
		memset(check, 0, sizeof(check));
		cout << BFS() << "\n";
	}
	return 0;
}