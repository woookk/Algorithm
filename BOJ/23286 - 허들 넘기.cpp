//
//  23286 - 허들 넘기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/16.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 5;
int N, M, T;
int u, v, h;
int s, e;

int d[301][301];

int main() {
    FASTIO
    cin >> N >> M >> T;
    
    for (int i = 1; i <= N; i++) {
        fill(d[i] + 1, d[i] + 1 + N, INF);
        d[i][i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> h;
        d[u][v] = min(d[u][v], h);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (d[j][k] > max(d[j][i], d[i][k])) d[j][k] = max(d[j][i], d[i][k]);
            }
        }
    }
    
    for (int i = 0; i < T; i++) {
        cin >> s >> e;
        if (d[s][e] == INF) d[s][e] = -1;
        cout << d[s][e] << "\n";
    }
    
    return 0;
}
