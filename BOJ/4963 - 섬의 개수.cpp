//
//  4963 - 섬의 개수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/23.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int board[51][51];
int vis[51][51];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){
    FASTIO;
    while(1){
        int w, h;
        cin >> w >> h;
        if(!w && !h) break;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
            }
        }
        for(int i = 0; i < h; i++){
            fill(vis[i], vis[i] + w, 0);
        }
        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i = 0; i < h; i ++){
            for(int j = 0; j < w; j++){
                if(board[i][j] && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    cnt++;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(int dir = 0; dir < 8; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                            if(!board[nx][ny]) continue;
                            if(vis[nx][ny]) continue;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
