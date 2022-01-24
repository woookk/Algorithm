#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int board[201][201];
int dist[31][201][201];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dx2[8] = { 2, 1, 2, 1, -2, -1, -2, -1 };
int dy2[8] = { 1, 2, -1, -2, 1, 2, -1, -2 };

int H, W, K;

int main(void) {
    FASTIO;
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j]; 
    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;
    while (!q.empty()) {
        int curZ, curX, curY;
        tie(curX, curY, curZ) = q.front();
        q.pop();
        if (curZ < K) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = curX + dx2[dir];
                int ny = curY + dy2[dir];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (board[nx][ny] || dist[curZ + 1][nx][ny]) continue;
                dist[curZ + 1][nx][ny] = dist[curZ][curX][curY] + 1;
                q.push({ nx, ny, curZ + 1});
            }
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (dist[curZ][nx][ny] || board[nx][ny]) continue;
            dist[curZ][nx][ny] = dist[curZ][curX][curY] + 1;
            q.push({ nx, ny, curZ});
        }
    }
    int ans =99999;
    for (int i = 0; i < K + 1; i++)
        if (dist[i][H - 1][W - 1]) ans = min(ans, dist[i][H - 1][W - 1]);
    if (ans != 99999) cout << ans-1;
    else cout << -1;
}