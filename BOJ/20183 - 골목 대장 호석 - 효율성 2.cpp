//
//  20183 - 골목 대장 호석 - 효율성 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/25.
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
typedef long long ll;

const ll INF = LONG_LONG_MAX / 5;
const int MX = 100005;
int N, M, A, B;
ll C;
int u, v, w;
vector<pair<ll, int>> adj[MX];
long long d[MX];
int low = 1, high;

bool isPossible(int limit) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(d, d + N + 1, INF);
    
    d[A] = 0;
    pq.push({d[A], A});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        if (d[cur.Y] != cur.X) continue;
        
        for (auto nx: adj[cur.Y]) {
            if (nx.X > limit) continue;
            nx.X += cur.X;
            if (d[nx.Y] <= nx.X) continue;
            d[nx.Y] = nx.X;
            pq.push({d[nx.Y], nx.Y});
        }
    }
    
    if (d[B] > C) return false;;
    return true;
}

int main() {
    FASTIO
    cin >> N >> M >> A >> B >> C;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        high = max(high, w);
    }
    
    while (low < high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) high = mid;
        else low = mid + 1;
    }
    
    if (isPossible(low)) cout << low << "\n";
    else cout << -1;
    return 0;
}
