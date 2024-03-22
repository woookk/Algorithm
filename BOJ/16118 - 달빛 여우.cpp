//
//  16118 - 달빛 여우.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/20.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 2;

int N, M;
int ans;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N + 1, INF);
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top();
        pq.pop();
        
        if (dist[curNode] < curDist) continue;
        
        for (auto [nxDist, nxNode]: adj[curNode]) {
            if (dist[nxNode] <= curDist + nxDist) continue;
            dist[nxNode] = curDist + nxDist;
            pq.push({dist[nxNode], nxNode});
        }
    }
    return dist;
}

vector<vector<int>> modifiedDijkstra(const vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(2, vector<int>(N + 1, INF));
    pq.push({0, {1, 1}});
    
    while (!pq.empty()) {
        auto [curDist, cur] = pq.top();
        auto [curNode, curStatus] = cur;
        pq.pop();
        
        if (dist[curStatus][curNode] < curDist) continue;
        
        for (auto [nxDist, nxNode]: adj[curNode]) {
            if (curStatus == 1) nxDist /= 2;
            else nxDist *= 2;
            
            if (dist[1 - curStatus][nxNode] <= curDist + nxDist) continue;
            dist[1 - curStatus][nxNode] = curDist + nxDist;
            pq.push({dist[1 - curStatus][nxNode], {nxNode, 1 - curStatus}});
        }
    }
    return dist;
}

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({d * 2, b});
        adj[b].push_back({d * 2, a});
    }
    
    auto distFox = dijkstra(adj);
    auto distWolf = modifiedDijkstra(adj);
    
    for (int i = 2; i <= N; i++) {
        if (min(distWolf[0][i], distWolf[1][i]) > distFox[i]) {
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}

/*
 관악산에는 1번부터 N번까지의 번호가 붙은 N개의 나무 그루터기가 있고, 그루터기들 사이에는 M개의 오솔길이 나 있다.
 달빛 여우와 달빛 늑대는 1번 나무 그루터기에서 살고 있다.
 보름달이 뜨면 나무 그루터기들 중 하나가 달빛을 받아 밝게 빛나게 된다. 그러면 달빛 여우와 달빛 늑대는 먼저 달빛을 독차지하기 위해 최대한 빨리 오솔길을 따라서 그 그루터기로 달려가야 한다.
 
 이때 달빛 여우는 늘 일정한 속도로 달려가는 반면, 달빛 늑대는 달빛 여우보다 더 빠르게 달릴 수 있지만 체력이 부족하기 때문에 다른 전략을 사용한다.
 달빛 늑대는 출발할 때 오솔길 하나를 달빛 여우의 두 배의 속도로 달려가고, 그 뒤로는 오솔길 하나를 달빛 여우의 절반의 속도로 걸어가며 체력을 회복하고 나서 다음 오솔길을 다시 달빛 여우의 두 배의 속도로 달려가는 것을 반복한다.
 달빛 여우가 달빛 늑대보다 먼저 도착할 수 있는 그루터기에 달빛을 비춰 주려고 한다. 이런 그루터기가 몇 개나 있는지 알아보는 프로그램을 작성
 
 다익스트라 알고리즘을 이용해서 달빛 여우와 달빛 늑대의 도착 시간을 구할 수 있다. 시간복잡도는 이 때 O(NlogN)이 된다.
 다익스트라 알고리즘을 이용해서 달빛 늑대의 최소 시간을 구할 때 각각의 그루터기별로 이전에 걸어서 도착했는지, 뛰어서 도착했는지에 대한 거리 값을 저장하는 방식으로 진행
 
 **달빛 늑대의 속도를 나누어주는 부분이 있으므로 모든 간선을 두 배씩 해주어 절삭되는 값이 없도록 해야한다.**
 */
