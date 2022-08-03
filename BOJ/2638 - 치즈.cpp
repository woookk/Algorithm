//
//  2638 - 치즈.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/02.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M, ans;
int board[101][101];
int vis[101][101];
int cnt[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool chk(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 1) return true;
        }
    }
    return false;
}

int main(){
    FASTIO
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    while(1){
        if(!chk()) break;
        for(int i = 0; i < N; i++){
            fill(vis[i], vis[i] + M, 0);
            fill(cnt[i], cnt[i] + M, 0);
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(vis[nx][ny]) continue;
                if(board[nx][ny] == 1){
                    cnt[nx][ny] += 1;
                    continue;
                }
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(cnt[i][j] >= 2) board[i][j] = 0;
            }
        }
        ans++;
    }
    cout << ans;
    return 0;
}
