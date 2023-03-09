//
//  2252 - 줄 세우기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/09.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int A, B;
vector<int> adj[32001];
int deg[32001];
vector<int> ans;

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        deg[B]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        
        for (int nx : adj[cur]) {
            deg[nx]--;
            if (deg[nx] == 0) {
                q.push(nx);
            }
        }
    }
    
    for (int x : ans) {
        cout << x << " ";
    }
    
    return 0;
}
