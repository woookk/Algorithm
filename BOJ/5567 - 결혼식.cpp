//
//  5567 - 결혼식.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/12.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
vector<int> node[501];
queue<int> q;
int vis[501];
int ans;

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (vis[cur] == 2) break;
        
        for (int i = 0; i < node[cur].size(); i++) {
            int nx = node[cur][i];
            if (vis[nx]) continue;
            q.push(nx);
            vis[nx] = vis[cur] + 1;
        }
    }
    
    for (int i = 2; i <= N; i++) {
        if (vis[i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
