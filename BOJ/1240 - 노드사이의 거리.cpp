//
//  1240 - 노드사이의 거리.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/02/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
int u, v, d;
vector<pair<int, int>> adj[1001];
bool vis[1001];

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        queue<pair<int, int>> q;
        fill(vis, vis + N + 1, 0);
        q.push({u, 0});
        while(!q.empty()) {
            auto [cur, dist] = q.front();
            q.pop();

            if (cur == v) {
                cout << dist << "\n";
                break;
            }
            
            for (auto [nx, nxDist] : adj[cur]) {
                if (vis[nx]) continue;
                vis[nx] = 1;
                q.push({nx, dist + nxDist});
            }
        }
    }
    return 0;
}
