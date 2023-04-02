//
//  10423 - 전기가 부족해.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/02.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M, K;
int u, v, w;
vector<pair<int, int>> adj[1001];
vector<bool> connect(1001, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cnt, ans;

int main() {
    FASTIO
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        pq.push({0, num});
    }
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    while (cnt < N) {
        auto cur = pq.top();
        pq.pop();
        if (connect[cur.Y]) continue;
        connect[cur.Y] = true;
        cnt++;
        ans += cur.X;
        
        for (auto nx : adj[cur.Y]) {
            if (connect[nx.Y]) continue;
            pq.push({nx.X, nx.Y});
        }
    }
    cout << ans;
    return 0;
}
