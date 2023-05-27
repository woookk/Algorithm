//
//  24042 - 횡단보도.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/27.
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
typedef long long ll;

const ll INF = LONG_LONG_MAX / 5;
int N, M;
int u, v;
vector<pair<ll, int>> adj[100005];
ll d[100005];


int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> u >> v;
        adj[u].push_back({i, v});
        adj[v].push_back({i, u});
    }
    
    fill(d, d + N + 1, INF);
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    d[1] = 0;
    pq.push({d[1], 1});
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        if (d[cur.Y] != cur.X) continue;
        
        for (auto nx: adj[cur.Y]) {
            if (nx.X < cur.X) {
                ll diff = cur.X - nx.X;
                ll tmp = diff / M;
                if (diff % M != 0) {
                    tmp++;
                }
                nx.X += M * tmp;
            }
            if (d[nx.Y] > nx.X) {
                d[nx.Y] = nx.X;
                pq.push({d[nx.Y], nx.Y});
            }
        }
    }
    cout << d[N];
    return 0;
}
