//
//  1987 - 알파벳.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/14.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int R, C;
char board[21][21];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int vis[26];
int ans;

void solve(int x, int y, int depth) {
    
    vis[board[x][y] - 'A'] = 1;
    ans = max(ans, depth);
    
    for (int dir = 0; dir < 4; dir ++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (vis[board[nx][ny] - 'A'] == 1) continue;
        solve(nx, ny, depth + 1);
    }
    vis[board[x][y] - 'A'] = 0;
}

int main() {
    FASTIO
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    solve(0, 0, 1);
    cout << ans;
    return 0;
}
