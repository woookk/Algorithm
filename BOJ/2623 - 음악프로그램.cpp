//
//  2623 - 음악프로그램.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/10.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
vector<int> adj[1001];
int deg[1001];

vector<int> ans;

int main() {
    FASTIO
    cin >> N >> M;
    
    int num, prev, cur;
    while (M--) {
        cin >> num >> prev;
        for (int i = 1; i < num; i++) {
            cin >> cur;
            adj[prev].push_back(cur);
            deg[cur]++;
            prev = cur;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        
        for (int nx: adj[cur]) {
            deg[nx]--;
            if (deg[nx] == 0) q.push(nx);
        }
    }
    
    if (ans.size() == N) {
        for (int x : ans) {
            cout << x << "\n";
        }
    }
    else {
        cout << "0\n";
    }
    return 0;
}
