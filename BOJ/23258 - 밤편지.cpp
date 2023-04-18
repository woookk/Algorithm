//
//  23258 - 밤편지.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/18.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 5;
int N, Q;
int C, s, e;

int d[301][301][301];

int main() {
    FASTIO
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        fill(d[0][i] + 1, d[0][i] + N + 1, INF);
        d[0][i][i] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int dist;
            cin >> dist;
            if (!dist) continue;
            d[0][i][j] = dist;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                d[i][j][k] = min(d[i - 1][j][k], d[i - 1][j][i] + d[i - 1][i][k]);
            }
        }
    }
    
    for (int i = 0; i < Q; i++) {
        cin >> C >> s >> e;
        if (d[C - 1][s][e] == INF) d[C - 1][s][e] = -1;
        cout << d[C - 1][s][e] << "\n";
    }
    return 0;
}
