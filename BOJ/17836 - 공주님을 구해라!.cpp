//
//  17836 - 공주님을 구해라!.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/22.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[101][101];
int dist[2][101][101];
int main(){
    FASTIO;
    int N, M, T;
    cin >> N >> M >> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    queue<tuple<int, int, bool>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while(!q.empty()){
        int curX, curY;
        bool flag;
        tie(curX, curY, flag) = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(dist[flag][nx][ny]) continue;
            if(board[nx][ny] == 2){
                dist[true][nx][ny] = dist[flag][curX][curY] + 1;
                q.push({nx, ny, true});
                continue;
            }
            else if(!flag && board[nx][ny] == 1) continue;
            dist[flag][nx][ny] = dist[flag][curX][curY] + 1;
            q.push({nx, ny, flag});
        }
    }
    int mn = 10000;
    for(int i = 0; i < 2; i++){
        if(dist[i][N-1][M-1]) mn = min(mn, dist[i][N-1][M-1]-1);
    }
    if(mn == 10000 || mn > T) cout << "Fail";
    else cout << mn;
}
