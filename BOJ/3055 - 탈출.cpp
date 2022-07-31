//
//  3055 - 탈출.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/31.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int R, C;
char board[51][51];
int dist[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    FASTIO
    cin >> R >> C;
    queue<pair<int, int>> q[2];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S'){
                q[1].push({i, j});
                dist[i][j] = 1;
            }
            if(board[i][j] == '*'){
                q[0].push({i, j});
            }
        }
    }
    while(!q[1].empty()){
        queue<pair<int, int>> nxq[2];
        for(int i = 0; i < 2; i++){
            while(!q[i].empty()){
                auto cur = q[i].front();
                q[i].pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                    if(board[nx][ny] == 'X') continue;
                    if(board[nx][ny] == '*') continue;
                    if(i == 0){
                        if(board[nx][ny] == 'D') continue;
                        nxq[i].push({nx, ny});
                        board[nx][ny] = '*';
                    }
                    else {
                        if(dist[nx][ny]) continue;
                        if(board[nx][ny] == 'D'){
                            cout << dist[cur.X][cur.Y];
                            return 0;
                        }
                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        nxq[i].push({nx, ny});
                    }
                }
            }
            q[i] = nxq[i];
        }
    }
    cout << "KAKTUS";
    return 0;
}
