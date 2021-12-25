#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int F, S, G, M[2];
int dist[1000001];

int main() {
	FASTIO;
	cin >> F >> S >> G >> M[0] >> M[1];
	M[1] = -M[1];
	queue<int> q;
	fill(dist+1, dist + F+1, -1);
	q.push(S);
	dist[S] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int nxt = cur + M[i];
			if (nxt < 1 || nxt > F) continue;
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	if (dist[G] >= 0) cout << dist[G];
	else cout << "use the stairs";
	return 0;
}