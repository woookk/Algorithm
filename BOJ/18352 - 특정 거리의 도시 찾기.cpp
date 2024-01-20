//
//  18352 - 특정 거리의 도시 찾기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/20.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, K, X;
vector<int> ans;

int main() {
    FASTIO
    cin >> N >> M >> K >> X;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    
    queue<int> q;
    vector<int> dist(N + 1, -1);
    dist[X] = 0;
    q.push(X);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (dist[cur] == K) {
            ans.push_back(cur);
            continue;
        }
        
        for (int nx: adj[cur]) {
            if (dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }
    if (ans.size() > 0) {
        sort(ans.begin(), ans.end());
        for (int x: ans) {
            cout << x << "\n";
        }
    }
    else {
        cout << -1;
    }
    return 0;
}

/*
 1번부터 N번까지의 도시와 M개의 단방향 도로가 존재한다. (모든 도로의 거리는 1)
 이 때 특정한 도시 X로부터 출발하여 도달할 수 있는 모든 도시 중에서, 최단 거리가 정확히 K인 모든 도시들의 번호를 출력하는 프로그램을 작성하시오.
 
 BFS 이용하여 최단 거리가 K인 도시를 구하는 방식으로 풀이
 
 **도시의 번호는 1-based index로 주어지기 때문에 OutOfBounds 주의**
 */
