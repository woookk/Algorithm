//
//  1916 - 최소비용 구하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int INF = INT_MAX / 5;
int N, M;
int u, v, w;
vector<pair<int, int>> adj[1005];
int d[1005];
int st, en;

int main() {
    FASTIO
    cin >> N >> M;
    
    fill(d, d + N + 1, INF);
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;
    
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
    
    cout << d[en];
    return 0;
}
