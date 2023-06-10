//
//  22868 - 산책 (large).cpp
//  Cpp
//
//  Created by 민병욱 on 2023/06/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define MX 200005

const int INF = INT_MAX / 5;

int n, m;
int s, e;
int dist[MX];
vector<pair<int, int>> adj[MX];
vector<bool> visited(MX, false);
int ans;

void dijkstra(int start, int end) {
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top();
        pq.pop();

        if (dist[cur_node] < cur_dist)
            continue;

        for (auto [nx_dist, nx_node] : adj[cur_node]) {
            
            if (visited[nx_node])
                continue;

            if (dist[nx_node] > nx_dist + cur_dist) {
                dist[nx_node] = nx_dist + cur_dist;
                pq.push({nx_dist + cur_dist, nx_node});
            }
        }
    }
    ans += dist[end];
}

void isVisited() {
    int cur_dist = 0;
    int cur_node = s;
    
    while (cur_node != e) {
        for (auto [nx_dist, nx_node] : adj[cur_node]) {
            if (cur_dist + nx_dist + dist[nx_node] == dist[s]) {
                cur_dist += nx_dist;
                visited[nx_node] = true;
                cur_node = nx_node;
                break;
            }
        }
    }
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second < b.second) return true;
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> s >> e;
    for (int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
        
    dijkstra(e, s);
    isVisited();
    dijkstra(e, s);
    cout << ans;

    return 0;
}

/*
 코로나로 인해 확진자 되버려 오늘부터 산책. 산책할 경로 정함
 현재 있는 곳 S에서 출발하여 다른 곳인 E를 찍고 다시 S로 돌아오는 경로를 만들어야한다. 산책을 할 때 이미 갔던 정점들을 다시 방문하기 싫어
 E에서 S로 올 때는 S에서 E로 갈 때 방문한 정점을 제외한 다른 정점으로 이동한다. 또, 산책 거리가 긴 것을 싫어하여 S -> E 가장 짧은 거리와 E -> S 가장 짤은 거리로 이동.
 S -> E 경로를 정할 때 가장 짧은 거리가 여러 개라면 사전 순으로 가장 먼저 오는 것으로 결정한다.
 
 먼저 다익스트라를 돌려 E -> S로 오는 최단 경로를 구한다. (양방향 통로이므로 S -> E 최단 경로와 값은 같음)
 E를 시작점으로 다익스트라 돌린 후 S부터 시작해서 DFS를 돌리면서
 현재 정점까지의 거리(cur_dist) + 현재 정점에서 다음 정점까지 거리(nx_dist) + 다음 정점에서 도착지까지의 거리(dist[nx_dist]) == 최단 경로이면
 해당 경로는 최단 경로에 포함되는 것으로 간주하고 문제 풀이.
 이후 최단 경로에 포함되는 정점 제외하고 다시 다익스트라 돌려 답을 구함.
 
 사전 순으로 방문하기 위해 간선 vector를 입력 된 순서와 상관없이 사전 순으로 정렬.
 
 실수: adj에서 사전 순으로 방문하기 위해서 연결된 정점(adj) 벡터 정렬할 때 간선의 가중치를 먼저 넣은 것 까먹고 정렬 진행...
 정렬이 간선의 가중치부터 되므로 예외 케이스에서 걸린다.
 */
