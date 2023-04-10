//
//  1956 - 운동.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/10.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 10;
int V, E;
int a, b, c;

int d[401][401];
int ans = INT_MAX;

int main() {
    FASTIO
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        fill(d[i] + 1 , d[i] + V + 1, INF);
    }
    
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            for (int k = 1; k <= V; k++) {
                if (d[j][k] > d[j][i] + d[i][k]) d[j][k] = d[j][i] + d[i][k];
            }
        }
    }
    
    for (int st = 1; st <= V; st++) {
        ans = min(ans, d[st][st]);
    }
    if (ans == INF) ans = -1;
    cout << ans;
    return 0;
}
