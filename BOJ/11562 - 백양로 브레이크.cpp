//
//  11562 - 백양로 브레이크.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/10.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 5;
int n, m, k;
int u, v, b;
int d[255][255];
int cnt[255][255];
int s, t;

int main() {
    FASTIO
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
    }
    
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> b;
        d[u][v] = 0;
        d[v][u] = !b;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (d[j][k] > d[j][i] + d[i][k]) d[j][k] = d[j][i] + d[i][k];
            }
        }
    }
    
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> s >> t;
        cout << d[s][t] << "\n";
    }
    return 0;
}
