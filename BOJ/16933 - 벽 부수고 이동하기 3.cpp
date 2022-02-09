//
//  16933 - 벽 부수고 이동하기 3.cpp
//  Cpp Algorithm
//
//  Created by 민병욱 on 2022/02/09.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string board[1001];
int dist[2][11][1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    FASTIO;
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    queue<tuple<int, int, int, bool>> q;
    q.push({ 0, 0, 0, 0 });
    dist[0][0][0][0] = 1;
    while (!q.empty()) {
        int curX, curY, cnt, day;
        tie(curX, curY, cnt, day) = q.front();
        if (curX == N - 1 && curY == M - 1) {
            cout << dist[day][cnt][curX][curY];
            return 0;
        }
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (board[nx][ny] == '0') {
                int nz = cnt;
                int nw = 1 - day;
                if (dist[nw][nz][nx][ny]) continue;
                dist[nw][nz][nx][ny] = dist[day][cnt][curX][curY] + 1;
                q.push({ nx, ny, nz, nw });
            }
            else {
                if (cnt == K) continue;
                if (!day) {
                    int nz = cnt + 1;
                    int nw = 1 - day;
                    if (dist[nw][nz][nx][ny]) continue;
                    dist[nw][nz][nx][ny] = dist[day][cnt][curX][curY] + 1;
                    q.push({ nx, ny, nz, nw });
                }
                else {
                    int nz = cnt;
                    int nw = 1 - day;
                    if (dist[nw][nz][curX][curY]) continue;
                    dist[nw][nz][curX][curY] = dist[day][cnt][curX][curY] + 1;
                    q.push({ curX, curY, nz, nw });
                }
            }
        }
    }
    cout << -1;
    return 0;
}
