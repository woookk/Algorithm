//
//  3197 - 백조의 호수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/18.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[1501];
bool vis1[1501][1501];
bool vis2[1501][1501];
bool found = false;

int main(){
    int R, C, lx, ly, cnt = 0;
    cin >> R >> C;
    queue<pair<int, int>> q;
    queue<pair<int, int>> nxq;
    queue<pair<int, int>> swan;
    queue<pair<int, int>> nxswan;
    for(int i = 0; i < R; i++)
        cin >> board[i];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == 'L'){
                lx = i;
                ly = j;
            }
            if(board[i][j] != 'X') {
                q.push({i, j});
                vis1[i][j] = 1;
            }
        }
    }
    swan.push({lx, ly});
    board[lx][ly] = '.';
    vis2[lx][ly] = 1;
    while(!found){
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx  >= R || ny >= C) continue;
                if(vis1[nx][ny]) continue;
                vis1[nx][ny] = 1;
                if(board[nx][ny] == 'X') nxq.push({nx,ny});
            }
        }
        while(!nxq.empty()){
            auto cur = nxq.front();
            nxq.pop();
            board[cur.X][cur.Y] = 1;
            q.push({cur.X, cur.Y});
        }
        cnt++;
        while(!swan.empty()){
            auto cur = swan.front();
            swan.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx  >= R || ny >= C) continue;
                if(vis2[nx][ny]) continue;
                if(board[nx][ny] == 'X'){
                    vis2[nx][ny] = 1;
                    nxswan.push({nx,ny});
                    continue;
                }
                else if (board[nx][ny] == 'L'){
                    found = true;
                    break;
                }
                else{
                    vis2[nx][ny] = 1;
                    swan.push({nx, ny});
                }
            }
        }
        while(!nxswan.empty()){
            auto cur = nxswan.front();
            nxswan.pop();
            swan.push({cur.X, cur.Y});
        }
    }
    cout << cnt;
    return 0;
}
