//
//  2637 - 장난감 조립.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int X, Y, K;
vector<pair<int, int>> adj[101];
bool isBasic[101];
int inDeg[101];
int cnt[101];

int main() {
    FASTIO
    cin >> N >> M;
    fill(isBasic, isBasic + N + 1, true);
    for (int i = 0; i < M; i++) {
        cin >> X >> Y >> K;
        adj[X].push_back({Y, K});
        isBasic[X] = false;
        inDeg[Y]++;
    }
    
    queue<int> q;
    q.push(N);
    cnt[N] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto [nx, c] : adj[cur]) {
            cnt[nx] += c * cnt[cur];
            inDeg[nx]--;
            
            if (inDeg[nx] == 0) q.push(nx);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (isBasic[i]) cout << i << " " << cnt[i] << "\n";
    }
    
    return 0;
}
