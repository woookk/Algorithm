//
//  1854 - K번째 최단경로 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int INF = INT_MAX / 5;
int n, m, k;
vector<pair<int, int>> adj[1005];
priority_queue<int> shortest[1005];
int dist[1005];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    shortest[1].push(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        for (auto nx : adj[cur.second]) {
            int new_dist = nx.first + cur.first;
            if (shortest[nx.second].size() < k) {
                shortest[nx.second].push(new_dist);
                pq.push({new_dist, nx.second});
            } else {
                if (shortest[nx.second].top() < new_dist) continue;
                shortest[nx.second].pop();
                shortest[nx.second].push(new_dist);
                pq.push({new_dist, nx.second});
            }
        }
    }
}

int main() {
    FASTIO
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    
    dijkstra();
    
    for (int i = 1; i <= n; i++) {
        if (shortest[i].size() < k) {
            cout << -1 << "\n";
        } else {
            cout << shortest[i].top() << "\n";
        }
    }
    return 0;
}
