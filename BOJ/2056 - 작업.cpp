//
//  2056 - 작업.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/13.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, ans;
int u, v;
vector<int> adj[10001];
int t[10001];
int inDeg[10001];

int main() {
    FASTIO
    cin >> N;
    for (u = 1; u <= N; u++) {
        cin >> t[u] >> inDeg[u];
        for (int i = 0; i < inDeg[u]; i++) {
            cin >> v;
            adj[v].push_back(u);
        }
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) q.push({t[i], i});
    }
    
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        ans = max(ans, cur.X);
        
        for (int nx : adj[cur.second]) {
            inDeg[nx]--;
            if (inDeg[nx] == 0) {
                t[nx] += cur.X;
                q.push({t[nx], nx});
            }
        }
    }
    
    cout << ans;
    return 0;
}
