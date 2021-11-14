#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool cnt[1001];
vector<int> line[1001];
queue<int> q;
int N, M, V;
int from, to;

void dfs(int start) {
	cout << start << ' ';
	cnt[start] = 1;
	for (int i = 0; i < line[start].size(); i++) {
		int next = line[start][i];

		if (cnt[next] == 0) {
			dfs(next);
		}
			
	}
}
void bfs(int start) {
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (cnt[front] == 0)
		{
			cout << front << ' ';
			cnt[front] = 1;
		}

		for (int i = 0; i < line[front].size(); i++) {
			if (cnt[line[front][i]] == 0) {
				q.push(line[front][i]);
				cout << line[front][i]<<' ';
				cnt[line[front][i]] = 1;
			}
		}
	}
}
int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		line[from].push_back(to);
		line[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		sort(line[i].begin(), line[i].end());
	}

	dfs(V);

	cout << "\n";
	fill(cnt, cnt + 1001, 0);
	q.push(V);
	bfs(V);
	return 0;
}