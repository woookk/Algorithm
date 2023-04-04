//
//  11404 - 플로이드.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/04.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 2;
int n, m;
int a, b, c;
int d[105][105];

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) d[i][j] = 0;
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
