//
//  1865 - 웜홀.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/21.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 2;

int TC;
int N, M, W;

void solve(vector<pair<pair<int, int>, int>> &adj) {
    vector<int> dist(N + 1, INF);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj.size(); j++) {
            int from = adj[j].first.first;
            int to = adj[j].first.second;
            int cost = adj[j].second;
            
            if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
        }
    }
    
    for (int i = 0; i < adj.size(); i++) {
        int from = adj[i].first.first;
        int to = adj[i].first.second;
        int cost = adj[i].second;
        if (dist[from] + cost < dist[to]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        vector<pair<pair<int, int>, int>> adj;
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj.push_back({{a, b}, c});
            adj.push_back({{b, a}, c});
        }
        for (int i = 0; i < W; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj.push_back({{a, b}, -c});
        }
        solve(adj);
    }
    return 0;
}

/*
    월드나라에는 N개의 지점이 있고, N개의 지점 사이에는 M개의 도로와 W개의 웜홀이 있다. (단 도로는 방향이 없으며 웜홀은 방향이 있다.)
    웜홀은 시작 위치에서 도착 위치로 가능 하나의 경로인데, 특이하게도 도착을 하게 되면 시작을 하였을 때보다 시간이 뒤로 가게 된다. (웜홀 내에서는 시계가 거꾸로 간다고 생각)
    한 지점에서 출발을 하여서 시간여행을 하기 시작하여 다시 출발을 하였던 위치로 돌아왔을 때, 출발 하였을 때보다 시간이 되돌아가 있는 경우가 있는지 없는지 궁금해졌다.
    가능한지 불가능한지 출력하는 프로그램 작성
    
    간선을 입력받을 때, 도로의 경우 +로 양방향으로 웜홀의 경우 -로 단방향으로 입력을 받은 후
    시작지점에서 다시 시작지점으로 돌아오는 최단경로를 확인했을 때 이 값이 음수인지 확인
    
    다익스트라의 경우 간선의 가중치가 음수일 경우 적용이 불가능하다.
    벨만포드 알고리즘을 이용하여 풀이 진행
    
    *벨만포드 알고리즘 최소비용을 구하는 알고리즘 중에서도, 한 정점에서 다른 모든 정점으로 가는데 걸리는 최소비용을 구하는데 사용하는 알고리즘
    '모든 경우의 수를 다 탐색해 가면서 최소비용'을 찾게 된다. 다익스트라 알고리즘과는 달리 그리디 하지 않게 동작한다.*
 */
