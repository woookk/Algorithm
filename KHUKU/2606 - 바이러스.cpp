#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool check[1001];
vector<int> line[1001];
int N, M, cnt = -1;
int from, to;

void dfs(int start) {
	check[start] = 1;
	cnt++;
	for (int i = 0; i < line[start].size(); i++) {
		int next = line[start][i];

		if (check[next] == 0) {
			dfs(next);
		}

	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		line[from].push_back(to);
		line[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		sort(line[i].begin(), line[i].end());
	}

	dfs(1);
	cout << cnt;
	return 0;
}