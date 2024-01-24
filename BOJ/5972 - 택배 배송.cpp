//
//  5972 - 택배 배송.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/23.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX;

int N, M;

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top();
        pq.pop();
        
        if (dist[curNode] != curDist) continue;
        
        for (auto [nxDist, nxNode] : adj[curNode]) {
            if (dist[nxNode] <= dist[curNode] + nxDist) continue;
            dist[nxNode] = dist[curNode] + nxDist;
            pq.push({dist[nxNode], nxNode});
        }
    }
    cout << dist[N] << "\n";
    return 0;
}

/**
 농부 현서는 농부 찬홍이에게 택배를 배달해줘야 합니다. 그리고 지금, 갈 준비를 하고 있습니다. 평화롭게 가려면 가는 길에 만나는 모든 소들에게 맛있는 여물을 줘야 합니다. 물론 현서는 구두쇠라서 최소한의 소들을 만나면서 지나가고 싶습니다.
 두 개의 헛간은 하나 이상의 길로 연결되어 있을 수도 있습니다. 농부 현서는 헛간 1에 있고 농부 찬홍이는 헛간 N에 있습니다.
 
 다익스트라를 이용해서 헛간 1에서 헛간 N까지의 최소 거리를 구하는 방식으로 풀이
 */
