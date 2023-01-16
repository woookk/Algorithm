//
//  1389 - 케빈 베이컨의 6단계 법칙.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
vector<int> node[101];
int visited[101];
int sum[101];
int ans;

void BFS(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nx : node[cur]) {
            if (visited[nx] >= 0) continue;
            q.push(nx);
            visited[nx] = visited[cur] + 1;
        }
    }
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        node[A].push_back(B);
        node[B].push_back(A);
    }
    
    for (int i = 1; i <= N; i++) {
        fill(visited, visited + 101, -1);
        BFS(i);
        for (int j = 1; j <= N; j++) {
            sum[i] += visited[j];
        }
    }
    
    ans = 1;
    for (int i = 1; i <= N; i++) {
        if (sum[ans] > sum[i]) ans = i;
    }
    cout << ans;
    return 0;
}
