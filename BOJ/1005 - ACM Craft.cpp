//
//  1005 - ACM Craft.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int T;
int N, K;
int D[1001];
int X, Y, W;
vector<int> adj[1001];
int inDeg[1001];

int main() {
    FASTIO
    cin >> T;
    while (T--) {
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        fill(inDeg + 1, inDeg + N + 1, 0);
        
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
        }
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            adj[X].push_back(Y);
            inDeg[Y]++;
        }
        cin >> W;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
        for (int i = 1; i <= N; i++) {
            if (inDeg[i] == 0) q.push({D[i], i});
        }
        
        while (!q.empty()) {
            auto cur = q.top();
            q.pop();
            for (int nx: adj[cur.Y]) {
                inDeg[nx]--;
                if (inDeg[nx] == 0) {
                    D[nx] += D[cur.Y];
                    q.push({D[nx], nx});
                }
            }
        }
        cout << D[W] << "\n";
    }
    return 0;
}
