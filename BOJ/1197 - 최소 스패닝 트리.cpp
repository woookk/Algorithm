//
//  1197 - 최소 스패닝 트리.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/28.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int V, E;
int A, B, C;
vector<pair<int, int>> adj[10001];

bool isMST[10001];
int cnt, ans;

int main() {
    FASTIO
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({C, B});
        adj[B].push_back({C, A});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    isMST[1] = true;
    for (auto nx : adj[1]) {
        pq.push({nx.X, nx.Y});
    }
    
    while (cnt < V - 1) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        isMST[cur.Y] = 1;
        cnt++;
        ans += cur.X;
        
        for (auto nx: adj[cur.Y]) {
            if (!isMST[nx.Y])
            pq.push({nx.X, nx.Y});
        }
    }
    
    cout << ans;
    return 0;
}
