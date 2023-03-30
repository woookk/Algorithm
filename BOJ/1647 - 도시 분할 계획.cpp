//
//  1647 - 도시 분할 계획.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/30.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
int A, B, C;
vector<pair<int, int>> adj[100001];
vector<bool> isMST(100001);
int cnt, ans, mx;

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({C, B});
        adj[B].push_back({C, A});
    }
    
    isMST[1] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto nx: adj[1]) {
        pq.push({nx.X, nx.Y});
    }
    
    
    while (cnt < N - 1) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        isMST[cur.Y] = true;
        cnt++;
        ans += cur.X;
        mx = max(mx, cur.X);
        
        for (auto nx: adj[cur.Y]) {
            if (isMST[nx.Y]) continue;
            pq.push({nx.X, nx.Y});
        }
    }
    ans -= mx;
    cout << ans;
    return 0;
}
