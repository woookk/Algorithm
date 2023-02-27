//
//  1068 - 트리.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/02/27.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int ROOT, del;
int ans;
vector<int> adj[51];

bool vis[51];

void DFS(int cur) {
    vis[cur] = true;
    
    int child = 0;
    for (int nx : adj[cur]) {
        if (nx == del) continue;
        DFS(nx);
        child++;
    }
    
    if (!child) {
        ans++;
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p == -1) {
            ROOT = i;
        }
        else {
            adj[p].push_back(i);
        }
    }
    cin >> del;
    if (del != ROOT)
        DFS(ROOT);
    
    cout << ans;
    
    return 0;
}
