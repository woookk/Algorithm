//
//  11779 - 최소비용 구하기 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int INF = INT_MAX / 5;
int n, m, st, en;
vector<pair<int, int>> adj[1005];
int d[1005];
int pre[1005];

int main() {
    FASTIO
    cin >> n >> m;
    fill(d, d + n + 1, INF);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;
    d[st] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[st], st});
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        if (d[cur.Y] != cur.X) continue;
        for (auto nx: adj[cur.Y]) {
            if (d[nx.Y] <= d[cur.Y] + nx.X) continue;
            d[nx.Y] = d[cur.Y] + nx.X;
            pq.push({d[nx.Y], nx.Y});
            pre[nx.Y] = cur.Y;
        }
        
    }
    
    cout << d[en] << "\n";
    
    vector<int> path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (auto v: path) {
        cout << v << " ";
    }
    return 0;
}
