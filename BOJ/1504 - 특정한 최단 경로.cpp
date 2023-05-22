//
//  1504 - 특정한 최단 경로.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int INF = INT_MAX / 10;
int N, E, ans;
int a, b, c;
int v1, v2;
vector<pair<int, int>> adj[1001];
int d[1001];

int solve(int st, int en) {
    fill(d, d + N + 1, INF);
    
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
    return d[en];
}

int main() {
    FASTIO
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;
    
    ans = min(solve(1, v1) + solve(v1, v2) + solve(v2, N), solve(1, v2) + solve(v2, v1) + solve(v1, N));
    if (ans >= INF) cout << -1;
    else cout << ans;
    return 0;
}
