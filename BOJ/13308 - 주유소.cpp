//
//  13308 - 주유소.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const ll INF = LONG_LONG_MAX / 2;
const int maxCost = 2505;

int N, M;

int main() {
    FASTIO
    cin >> N >> M;
    vector<int> gasStation(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> gasStation[i];
    }
    
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    pq.push({0, {1, gasStation[1]}});
    vector<vector<ll>> totalCost(N + 1, vector<ll>(maxCost, INF));
    totalCost[1][gasStation[1]] = 0;
    
    while (!pq.empty()) {
        auto [curCost, cur] = pq.top();
        auto [curNode, curPrice] = cur;
        pq.pop();
        
        if (totalCost[curNode][curPrice] < curCost) continue;
        
        for (auto [nxDist, nxNode]: adj[curNode]) {
            ll nxCost = curCost + curPrice * nxDist;
            int nxPrice = min(curPrice, gasStation[nxNode]);
            
            if (totalCost[nxNode][curPrice] <= nxCost) continue;
            totalCost[nxNode][curPrice] = nxCost;
            pq.push({nxCost, {nxNode, nxPrice}});
        }
    }
    
    cout << *min_element(totalCost[N].begin(), totalCost[N].end());
    return 0;
}

/*
 어떤 나라에는 N개의 도시가 있고, 각 도시는 1번부터 N번까지 번호가 붙어 있다. 또, 서로 다른 두 도시를 양방향으로 직접 연결하는 M개의 도로가 있다.
 1번 도시에서 N번 도시로 자동차를 이용하여 이동하려고 한다. 처음 출발할 때 자동차에 기름이 없어서 주유소에서 기름을 넣고 출발하여야 한다.
 기름통의 크기는 무제한이어서 많은 기름을 넣을 수 있다. 도로를 이용하여 이동할 때 1km마다 1리터의 기름을 사용한다. 각 도시에는 단 하나의 주유소가 있으며, 도시마다 주유소의 리터당 가격은 다를 수 있다.
 각 도시에 있는 주유소의 기름 가격과, 각 도로들의 길이를 입력으로 받아 1번 도시에서 N번 도시로 이동하는 최소의 비용을 계산하는 프로그램을 작성
 
 다익스트라 알고리즘을 이용하여 풀이
 각각의 도시에서 현재까지 지난 최소 가격에 대한 비용을 갱신해주는 방식으로 다익스트라 알고리즘을 변형해서 풀이
 
 **전체 비용이 INT 범위를 초과하므로 오버플로우 주의할 것**
 */
