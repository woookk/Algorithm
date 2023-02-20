//
// Created by 민병욱 on 2023/02/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MX 501

int n, m;
vector<int> adj[MX];
bool vis[MX], isTree;
int trees;

void DFS(int cur, int prev) {
    for (int nx: adj[cur]) {
        if (nx == prev) continue;
        if (vis[nx]) {
            isTree = false;
            continue;
        }
        vis[nx] = true;
        DFS(nx, cur);
    }
}

int main() {
    FASTIO
    for (int TC = 1; ; TC++) {
        cin >> n >> m;
        if (!n && !m) break;

        fill(vis, vis + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        trees = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            isTree = true;
            DFS(i, -1);
            trees += isTree;
        }

        cout << "Case " << TC << ": ";
        if (!trees) {
            cout << "No trees.\n";
        }
        else if (trees == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << trees << " trees.\n";
        }
    }
    return 0;
}