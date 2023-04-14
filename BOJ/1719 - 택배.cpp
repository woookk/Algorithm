//
//  1719 - 택배.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/13.
//

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 5;
int n, m;
int u, v, c;
int d[201][201];
int nx[201][201];

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
        d[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        d[u][v] = min(d[u][v], c);
        d[v][u] = min(d[v][u], c);
        nx[u][v] = v;
        nx[v][u] = u;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (d[j][k] > d[j][i] + d[i][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                    nx[j][k] = nx[j][i];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << "- ";
            else
                cout << nx[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
