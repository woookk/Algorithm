//
//  2325 - 개코전쟁.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, ans;

int dijkstra(vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> dist(N + 1, INT_MAX / 2);
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
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> dist(N + 1, INT_MAX / 2);
    vector<int> prev(N + 1);
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top();
        pq.pop();
        
        if (dist[curNode] < curDist) continue;
        
        for (auto [nxDist, nxNode]: adj[curNode]) {
            if (dist[nxNode] <= curDist + nxDist) continue;
            dist[nxNode] = curDist + nxDist;
            pq.push({ dist[nxNode], nxNode });
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
                nxDist = INT_MAX / 2;
                ans = max(ans, dijkstra(adj));
                nxDist = cache;
                curNode = prevNode;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

/*
 개미왕국은 코끼리왕국을 공격하기로 결정하였다. 지도에서 개미왕국은 1번 정점에 위치해 있고 코끼리 왕국은 N번 정점에 위치해 있다.
 따라서 개미왕국이 1번 정점에서 N번 정점으로 공격을 하러 가는 상황이다. (개미왕국은 최단거리로 이동을 하게 되고, 코끼리왕국은 움직이지 않는다.)
 전쟁을 막으려고 할 때, 협상을 할 시간을 벌기 위해 개미왕국이 코끼리왕국에 도착하는 시간을 최대한 늦추려고 한다. 사자왕국의 도움을 빌어 도로 중 딱 하나를 파괴하려고 하는데 어느 도로를 파괴해야 개미왕국이 최단 거리로 가더라도 그 거리를 최대로 할 수 있을까?
 적당한 도로 하나를 파괴했을 때 1번 정점에서 N번 정점으로의 최단거리의 최댓값을 출력하는 프로그램을 작성
 
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
