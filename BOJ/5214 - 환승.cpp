//
// Created by 민병욱 on 2023/02/14.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K, M;
vector<int> adj[101001];
int dist[101001];

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nx: adj[cur]) {
            if (dist[nx] != -1) continue;
            q.push(nx);
            if (nx > N)
                dist[nx] = dist[cur];
            else
                dist[nx] = dist[cur] + 1;
        }
    }
}

int main() {
    FASTIO
    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= K; j++) {
            int st;
            cin >> st;
            adj[N + i].push_back(st);
            adj[st].push_back(N + i);
        }
    }

    fill(dist, dist + N + M + 1, -1);
    bfs();

    cout << dist[N];
    return 0;
}

