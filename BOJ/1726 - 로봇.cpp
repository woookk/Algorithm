//
//  1726 - 로봇.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/20.
//

#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;

int M, N;
int board[101][101];
int dist[5][101][101];

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

int stRow, stCol, stDir, endRow, endCol, endDir;
queue<tuple<int, int, int>> q;

int main() {
    FASTIO
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    cin >> stRow >> stCol >> stDir;
    cin >> endRow >> endCol >> endDir;
    
    stRow--; stCol--; endRow--; endCol--;
    q.push({stRow, stCol, stDir});
    dist[stDir][stRow][stCol] = 1;
    
    while (!q.empty()) {
        int curX, curY, curDir, depth;
        tie(curX, curY, curDir) = q.front();
        q.pop();
        depth = dist[curDir][curX][curY];
        
        if (curDir == EAST || curDir == WEST) {
            if (!dist[SOUTH][curX][curY]) {
                dist[SOUTH][curX][curY] = depth + 1;
                q.push({curX, curY, SOUTH});
            }
            if (!dist[NORTH][curX][curY]) {
                dist[NORTH][curX][curY] = depth + 1;
                q.push({curX, curY, NORTH});
            }
        }
        else {
            if (!dist[EAST][curX][curY]) {
                dist[EAST][curX][curY] = depth + 1;
                q.push({curX, curY, EAST});
            }
            if (!dist[WEST][curX][curY]) {
                dist[WEST][curX][curY] = depth + 1;
                q.push({curX, curY, WEST});
            }
        }
        
        for (int k = 1; k <= 3; k++) {
            int nx = curX + dx[curDir] * k;
            int ny = curY + dy[curDir] * k;
            
            if (dist[curDir][nx][ny]) continue;
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) break;
            if (board[nx][ny]) break;
            dist[curDir][nx][ny] = depth + 1;
            q.push({nx, ny, curDir});
        }
    }
    
    cout << dist[endDir][endRow][endCol] - 1;
    return 0;
}
