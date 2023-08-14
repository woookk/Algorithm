//
//  1922 - 네트워크 연결.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/15.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, ans;
vector<pair<int, int>> node[1005];
vector<bool> isMST(1005, false);

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back({c, b});
        node[b].push_back({c, a});
    }
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [cost, curNode] = pq.top();
        pq.pop();
        
        if (isMST[curNode]) continue;
        isMST[curNode] = true;
        ans += cost;
        
        for (auto [nxCost, nxNode] : node[curNode]) {
            if (isMST[nxNode]) continue;
            pq.push({nxCost, nxNode});
        }
    }
    cout << ans;
    return 0;
}

/*
 도현이는 컴퓨터와 컴퓨터를 모두 연결하는 네트워크를 구축하려고 한다. 허브가 있지 않아 컴퓨터와 컴퓨터를 직접 연결해야 한다.
 모두가 자료를 공유하기 위해서는 모든 컴퓨터가 연결이 되어 있어야 한다.
 컴퓨터를 연겷하는 비용을 최소로 하여야 컴퓨터를 연결하는 비용 외에 다른 곳에 돈을 더 쓸 수 있을 것. 모든 컴퓨터를 연결하는데 필요한 최소 비용을 구하라.
 
 최소 신장 트리를 구하면 된다.
 */
