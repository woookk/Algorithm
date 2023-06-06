//
//  5719 - 거의 최단 경로.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/06/02.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 5;

int n, m;
int st, en;
vector<int> dist(505);
vector<pair<int, int>> adj[505];
vector<int> shortest_paths[505];
vector<bool> vis(505);

void dijkstra(int cur) {
    fill(dist.begin(), dist.end(), INF);
    dist[cur] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[cur], cur});
    
    while (!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top();
        pq.pop();
        
        if (cur_dist != dist[cur_node]) continue;
        
        for (auto [nx_dist, nx_node]: adj[cur_node]) {
            if (nx_dist == -1) continue;
            if (dist[nx_node] < dist[cur_node] + nx_dist) continue;
            if (dist[nx_node] == dist[cur_node] + nx_dist) {
                shortest_paths[nx_node].push_back(cur_node);
            } else {
                dist[nx_node] = dist[cur_node] + nx_dist;
                shortest_paths[nx_node].clear();
                shortest_paths[nx_node].push_back(cur_node);
                pq.push({dist[nx_node], nx_node});
            }
        }
    }
}

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (vis[cur]) continue;
        vis[cur] = true;
        
        for (int prev: shortest_paths[cur]) {
            for (int nx_idx = 0; nx_idx < adj[prev].size(); nx_idx++) {
                if (adj[prev][nx_idx].second == cur) {
                    adj[prev][nx_idx].first = -1;
                }
            }
            q.push(prev);
        }
    }
}

int main() {
    FASTIO
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> st >> en;
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            shortest_paths[i].clear();
        }
        fill(vis.begin(), vis.end(), 0);
        
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({p, v});
        }

        dijkstra(st);
        bfs(en);
        dijkstra(st);
        
        if (dist[en] == INF) cout << -1 << "\n";
        else cout << dist[en] << "\n";
    }
    return 0;
}
