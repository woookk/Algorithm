//
//  17182 - 우주 탐사선.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/08.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int D[11][11];

int vis[11];
int ans;

int MN = INT_MAX;

int travel(int start, int depth) {
    
    if (depth == N - 1) {
        MN = min(ans, MN);
    }
    
    
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            ans += D[start][i];
            travel(i, depth + 1);
            ans -= D[start][i];
            vis[i] = false;
        }
    }
    return MN;
}

int main() {
    FASTIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (D[j][k] > D[j][i] + D[i][k]) D[j][k] = D[j][i] + D[i][k];
            }
        }
    }
    
    vis[K] = true;
    cout << travel(K, 0);
    return 0;
}
