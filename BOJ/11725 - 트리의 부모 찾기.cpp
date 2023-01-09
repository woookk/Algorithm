//
//  11725 - 트리의 부모 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/08.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
vector<int> node[100001];
int parent[100001];
int visited[100001];

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < node[cur].size(); i++) {
            int nx = node[cur][i];
            if (visited[nx]) continue;
            parent[nx] = cur;
            q.push(nx);
            visited[nx] = 1;
        }
    }
    
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}
