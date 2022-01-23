#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int dist[100001];

int main() {
	FASTIO;
	cin >> N >> K;
	fill(dist, dist + 100001, -1);
	dist[N] = 0;
	queue<int> q;
	q.push(N);
	while (dist[K] == -1) {
		int cur = q.front();
		q.pop();
		int nx = 2 * cur;
		if (nx < 0 || nx > 100000);
		else if (dist[nx] != -1);
		else {
			dist[nx] = dist[cur];
			q.push(nx);
		}
		for (int nx : {cur - 1, cur + 1}) {
			if (nx < 0 || nx > 100000) continue;
			if (dist[nx] != -1) continue;
			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}
	cout << dist[K];
	return 0;
}