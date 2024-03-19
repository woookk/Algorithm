//
//  2307 - 도로검문.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 2;

int N, M;
int ans = -1;

int dijkstra(vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> dist(N + 1, INF);
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top();
        pq.pop();
        
        if (dist[curNode] < curDist) continue;
        
        for (auto [nxDist, nxNode]: adj[curNode]) {
            if (dist[nxNode] <= curDist + nxDist) continue;
            dist[nxNode] = curDist + nxDist;
            pq.push({ dist[nxNode], nxNode });
        }
    }
    return dist[N];
}

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({ t, b });
        adj[b].push_back({ t, a });
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N + 1, INF);
    vector<int> prev(N + 1);
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top();
        pq.pop();
        
        if (dist[curNode] < curDist) continue;
        
        for (auto [nxDist, nxNode]: adj[curNode]) {
            if (dist[nxNode] <= curDist + nxDist) continue;
            dist[nxNode] = curDist + nxDist;
            pq.push({ dist[nxNode], nxNode});
            prev[nxNode] = curNode;
        }
    }
    
    
    int curNode = N;
    while (true) {
        if (curNode == 1) {
            break;
        }

        int prevNode = prev[curNode];
        for (auto& [nxDist, nxNode]: adj[prevNode]) {
            if (curNode == nxNode && dist[curNode] - nxDist == dist[prevNode]) {
                int cache = nxDist;
                nxDist = INF;
                ans = max(ans, dijkstra(adj));
                nxDist = cache;
                curNode = prevNode;
                break;
            }
        }
    }
    if (ans == INF) {
        ans = -1;
    }
    else {
        ans -= dist[N];
    }
    cout << ans;
    return 0;
}

/*
 어떤 범죄용의자가 입력 데이터에 표시된 도시로 진입하여 이 도시를 가장 빠른 시간 내에 빠져나가고자 한다. 그런데 이 사실을 알고 있는 경찰이 어떤 하나의 도로를 선택하여 이 도로에서 검문을 하려고 한다.
 따라서 용의자는 이 도로를 피해서 가장 빠르게 도시를 탈출하고자 한다. 이 경우 경찰이 검문을 위하여 선택하는 도로에 따라서 용의자에 가장 빠른 탈출 시간은 검문이 없을 때에 비하여 더 늘어날 수 있다.
 도로검문을 통하여 얻을수 있는 탈출의 최대 지연시간을 계산하는 프로그램을 작성하자.
 
 각각의 도로를 모두 없애보고 최단 거리를 구하는 방식의 풀이는 시간복잡도가 O(M * NlogN)이므로 시간 초과가 발생한다.
 다익스트라를 이용해서 최단 거리를 구하고 최단 거리에 포함되는 도로들을 없애보는 방식으로 풀이 진행
 최단 거리에 포함되지 않는 도로를 제거한다면 최단 거리에 포함되는 간선을 따라 이동하게되므로 최단 거리에 포함되는 도로들만을 가지고 수행한다.
 시간복잡도는 O(N * NlogN)이된다.
 
 **최단 경로가 여러 개일 경우**
 위 부분에 대한 생각을 고려하지 않고 단순히 최단 경로에 포함되는 도로를 제거하는 방식으로 풀이를 진행
 
 최단 경로가 여러 개인 경우에는, 두 가지 경우로 나눠서 생각할 수 있다.
 1. 최단 경로가 겹치지 않을 경우
    위 경우에는 최단 경로 둘 중에 어느 도로를 제거하여도 항상 최단 거리가 나오는 것을 알 수 있다.
 2. 최단 경로가 겹치는 경우
    겹치지 않는 부분에서 끊을 경우 1번의 경우와 마찬 가지로 항상 최단 거리가 나오는 것을 알 수 있고
    답이 될 수 있는 경우는 겹치는 부분에서 제거하는 경우이다.
 그러므로 한 최단 경로에서 도로들을 제거하는 방식으로 풀이가 가능하다.
 */
