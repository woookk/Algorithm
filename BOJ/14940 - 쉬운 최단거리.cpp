//
//  14940 - 쉬운 최단거리.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/31.
//

#include <iostream>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
int board[1005][1005];
int dist[1005][1005];

queue<pair<int, int>> q;

void bfs() {
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (!board[nx][ny]) continue;
            if (dist[nx][ny]) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 1;
            }
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) {
                cout << dist[i][j] << " ";
                continue;
            }
            cout << dist[i][j] - 1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    FASTIO
    input();
    bfs();
    print();
    return 0;
}
