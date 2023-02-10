//
// Created by 민병욱 on 2023/02/10.
//
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
vector<int> adj[2001];
int vis[2001];

int ans;

void DFS(int cur, int depth) {
    if (depth == 4) {
        ans = 1;
        return;
    }
    vis[cur] = 1;
    for (int nx: adj[cur]) {
        if (ans) return;
        if (vis[nx]) continue;
        DFS(nx, depth + 1);
    }
    vis[cur] = 0;
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 0);
        if (ans) break;
    }

    cout << ans;
    return 0;
}
