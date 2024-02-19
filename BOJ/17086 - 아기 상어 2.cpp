//
//  17086 - 아기 상어 2.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

int N, M;

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int> (M));
    vector<vector<int>> dist(N, vector<int> (M, - 1));
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
 N * M 크기의 공간에 아기 상어 여러 마리가 있다. 한 칸에는 아기 상어가 최대 1마리 존재한다.
 어떤 칸의 안전 거리는 그 칸과 가장 거리가 가까운 아기 상어와의 거리이다. 두 칸의 거리는 하나의 칸에서 다른 칸으로 가기 위해서 지나야 하는 칸의 수이고, 이동은 인접한 8방향(대각선 포함)이 가능하다.
 
 아기 상어가 있는 칸을 시작 점으로 Breadth-First Search를 진행해서 모든 칸까지의 안전 거리를 구할 수 있다.
 */
