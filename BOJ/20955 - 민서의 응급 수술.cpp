//
// Created by 민병욱 on 2023/02/28.
//
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, u, v;
vector<int> adj[100001];
bool vis[100001];
int trees, cuts;

void DFS(int cur, int parent) {
    vis[cur] = 1;

    for (int nx: adj[cur]) {
        if (nx == parent) continue;
        if (vis[nx]) {
            cuts++;
            continue;
        }
        DFS(nx, cur);
    }
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            DFS(i, -1);
            trees++;
        }
    }
    cout << trees - 1 + cuts / 2;
    return 0;
}