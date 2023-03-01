//
// Created by 민병욱 on 2023/03/01.
//
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m, p;
vector<int> adj[100001];
int ans[100001];

void DFS(int cur) {

    for (int nx : adj[cur]) {
        ans[nx] += ans[cur];
        DFS(nx);
    }
}

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        if (p != -1) {
            adj[p].push_back(i);
        }
    }

    while(m--) {
        int i, w;
        cin >> i >> w;
        ans[i] += w;
    }

    DFS(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}