//
//  17835 - 면접보는 승범이네.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/25.
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

const long long INF = LONG_LONG_MAX/ 5;
int N, M, K;
int U, V, C;
vector<pair<long long, int>> adj[100005];
long long d[100005];

int main() {
    FASTIO
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> C;
        adj[V].push_back({C, U});
    }
    
    fill(d, d + N + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        d[num] = 0;
        pq.push({d[num], num});
    }
    
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
    
    int idx = max_element(d + 1, d + N + 1) - d;
    cout << idx << "\n" << d[idx];
    return 0;
}
