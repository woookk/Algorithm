//
//  2636 - 치즈.cpp
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

int R, C;
int pre, ans;
int board[101][101];
int vis[101][101];
int cnt[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool chk(){
    int num = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(cnt[i][j] >= 1){
                board[i][j] = 0;
                continue;
            }
            if(board[i][j] == 1) num++;
        }
    }
    if(num){
        pre = num;
        return true;
    }
    else return false;
}

int main(){
    FASTIO
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }
    while(1){
        if(!chk()){
            break;
        }
        for(int i = 0; i < R; i++){
            fill(vis[i], vis[i] + C, 0);
            fill(cnt[i], cnt[i] + C, 0);
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if(vis[nx][ny]) continue;
                if(board[nx][ny] == 1){
                    cnt[nx][ny] += 1;
                    continue;
                }
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
        ans++;
    }
    cout << ans << "\n" << pre;
    return 0;
}
