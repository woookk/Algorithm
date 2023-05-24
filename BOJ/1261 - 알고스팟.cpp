//
//  1261 - 알고스팟.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/24.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
const int INF = INT_MAX / 5;

int N, M;
bool b[101][101];
int d[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve(){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    d[1][1] = 0;
    pq.push({0, 1, 1});
    
    while (!pq.empty()) {
        int cw, cx, cy;
        tie(cw, cx, cy) = pq.top();
        pq.pop();
        if(d[cx][cy] != cw) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx > N || nx < 1) continue;
            if(ny > M || ny < 1) continue;
            int nw = cw + b[nx][ny];
            if(nw < d[nx][ny]) {
                d[nx][ny] = nw;
                pq.push({nw, nx, ny});
            }
        }
    }
    return d[N][M];
}

int main(){
    FASTIO
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
      string str;
      cin >> str;
      for(int j = 1; j <= M; j++) {
          b[i][j] = str[j - 1] - '0';
      }
    }
    
    for (int i = 1; i <= N; i++) {
        fill(d[i] + 1, d[i] + M + 1, INF);
    }
    cout << solve();
    return 0;
}
