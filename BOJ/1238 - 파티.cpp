//
//  1238 - 파티.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/20.
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
int N, M, en, ans;
int u, v, t;
vector<pair<int, int>> adj[1005];
int d[1005];

int solve(int st, int en) {
    fill(d, d + N + 1, INF);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        if (cur.X != d[cur.Y]) continue;
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
    cin >> N >> M >> en;
    
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> t;
        adj[u].push_back({t, v});
    }

    for (int st = 1; st <= N; st++) {
        ans = max(ans, solve(st, en) + solve(en, st));
    }
    cout << ans;
    return 0;
}
