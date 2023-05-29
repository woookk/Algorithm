//
//  1162 - 도로포장.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/28.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const ll INF = LONG_LONG_MAX / 5;
int N, M, K;
int u, v, w;
vector<pair<ll, int>> adj[10005];

ll dist[21][10005];

int main() {
    FASTIO
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    for (int i = 0; i <= K; i++) {
        fill(dist[i], dist[i] + N + 1, INF);
    }
    
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    
    for (int i = 0; i <= K; i++) {
        dist[i][1] = 0;
    }
    pq.push({0, 0, 1});
    
    while (!pq.empty()) {
        auto [curDist, curCnt, curNode] = pq.top();
        pq.pop();
    
        if (dist[curCnt][curNode] != curDist) continue;
        
        for (auto [nxDist, nxNode] : adj[curNode]) {
            if (curCnt < K) {
                if (curDist < dist[curCnt + 1][nxNode]) {
                    dist[curCnt + 1][nxNode] = curDist;
                    pq.push({curDist, curCnt + 1, nxNode});
                }
            }
            
            nxDist += curDist;
            if (nxDist >= dist[curCnt][nxNode]) continue;
            dist[curCnt][nxNode] = nxDist;
            pq.push({nxDist, curCnt, nxNode});
        }
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dist[i][N]);
    }
    cout << ans;
    return 0;
}
