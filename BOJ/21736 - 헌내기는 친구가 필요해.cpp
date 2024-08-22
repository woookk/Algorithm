//
//  21736 - 헌내기는 친구가 필요해.cpp
//  cpp
//
//  Created by 병욱 민 on 8/22/24.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
int ans;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'I') {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (board[nx][ny] == 'X') continue;
            if (visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
            if (board[nx][ny] == 'P') {
                ans++;
            }
        }
    }
    if (ans == 0) {
        cout << "TT";
    }
    else {
        cout << ans;
    }
    return 0;
}
