//
//  1976 - 여행 가자.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/02.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
bool ans = true;

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int> (N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
        }
    }
    
    vector<int> visited(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = i;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int nx = 1; nx <= N; nx++) {
                if (visited[nx]) continue;
                if (!adj[cur][nx]) continue;
                visited[nx] = i;
                q.push(nx);
            }
        }
    }
 
    int prev, cur;
    cin >> prev;
    for (int i = 1; i < M; i++) {
        cin >> cur;
        if (visited[prev] != visited[cur]) {
            ans = false;
            break;
        }
        prev = cur;
    }
    if (ans) cout << "YES";
    else cout << "NO";
    return 0;
}

/*
 친구들과 함께 여행을 가려고 한다. 한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다.
 여행 일정이 주어졌을 때, 여행 경로가 가능한 것인지 알아보자. 중간에 다른 도시를 경유해서 여행을 할 수도 있다.
 
 각각의 도시를 시작점으로 하여 BFS 돌린 후 도달 가능한 도시들을 표시하는 방식으로 풀이 진행
 */
