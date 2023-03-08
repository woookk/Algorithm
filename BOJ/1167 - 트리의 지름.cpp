//
//  1167 - 트리의 지름.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int u, v, e;
vector<pair<int, int>> adj[100001];
int dist[100001];
int furthest;

void dfs(int cur) {
    for (auto [nx, weight] : adj[cur]) {
        if (dist[nx] != -1) continue;
        dist[nx] = dist[cur] + weight;
        dfs(nx);
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> u;
        while (1) {
            cin >> v;
            if (v == -1) break;
            cin >> e;
            adj[u].push_back({v, e});
        }
    }
    
    fill(dist + 1, dist + N + 1, -1);
    dist[1] = 0;
    dfs(1);
    for (int i = 1; i <= N; i++) {
        if (dist[furthest] < dist[i]) {
            furthest = i;
        }
    }
    
    fill (dist + 1, dist + N + 1, -1);
    dist[furthest] = 0;
    dfs(furthest);
    
    cout << *max_element(dist + 1, dist + N + 1);
    return 0;
}
