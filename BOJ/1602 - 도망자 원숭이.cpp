//
//  1602 - 도망자 원숭이.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/19.
//

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int INF = INT_MAX / 5;
int N, M, Q;
int a, b, d;
int s, t;

int dist[501][501];
int w[501][501];

vector<pair<int, int>> delay;

int main() {
    FASTIO
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> w[i][i];
        delay.push_back({w[i][i], i});
    }
    
    sort(delay.begin(), delay.end());
    
    for (int i = 1; i <= N; i++) {
        fill(dist[i] + 1, dist[i] + N + 1, INF);
        for (int j = 1; j <= N; j++) {
            w[i][j] = max(w[i][i], w[j][j]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        dist[i][i] = w[i][i];
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> d;
        int maxDelay = max(w[b][b], w[a][a]);
        dist[a][b] = d + maxDelay;
        dist[b][a] = d + maxDelay;
    }
    
    for (auto middle : delay) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int nxDelay = max(middle.X, w[i][j]);
                
                int nx = (dist[i][middle.Y] - w[i][middle.Y]) + (dist[middle.Y][j] - w[middle.Y][j]) + nxDelay;
                
                if (dist[i][j] > nx) {
                    dist[i][j] = nx;
                    w[i][j] = nxDelay;
                }
            }
        }
    }
    
    for (int i = 0; i < Q; i++) {
        cin >> s >> t;
        if (dist[s][t] == INF) dist[s][t] = -1;
        cout << dist[s][t] << "\n";
    }
    return 0;
}
