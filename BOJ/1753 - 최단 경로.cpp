//
//  1753 - 최단 경로.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/20.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int INF = INT_MAX / 5;
int v, e, st;
vector<pair<int, int>> adj[20005];
int d[20005];

int main() {
    FASTIO
    cin >> v >> e >> st;
    fill(d, d + v + 1, INF);
    
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        if (d[cur.Y] != cur.X) continue;
        for (auto nx: adj[cur.Y]) {
            if (d[nx.Y] <= d[cur.Y] + nx.X) continue;
            d[nx.Y] = d[cur.Y] + nx.X;
            pq.push({d[nx.Y], nx.Y});
        }
    }
    
    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
    return 0;
}
