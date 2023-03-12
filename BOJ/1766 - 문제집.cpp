//
//  1766 - 문제집.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/12.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int A, B;
vector<int> adj[32001];
int inDeg[32001];
vector<int> ans;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    FASTIO
    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        adj[A].push_back(B);
        inDeg[B]++;
    }
    
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        ans.push_back(cur);
        
        for (int nx: adj[cur]) {
            inDeg[nx]--;
            if (inDeg[nx] == 0) q.push(nx);
        }
    }
    
    for (int x: ans) {
        cout << x << " ";
    }
    return 0;
}
