//
//  14503 - 로봇 청소기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/22.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, ans;
int board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void calc(int x, int y, int dir){
    if(board[x][y] == 0){
        board[x][y] = -1;
        ans++;
    }
    for(int i = 0; i < 4; i++){
        dir = (dir + 3) % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(board[nx][ny] != 0) continue;
        else {
            calc(nx, ny, dir);
            return;
        }
    }
    if(board[x - dx[dir]][y - dy[dir]] == 1) return;
    else {
        calc(x - dx[dir], y - dy[dir] , dir);
    }
}

int main(){
    FASTIO;
    int r, c, dir;
    cin >> N >> M;
    cin >> r >> c >> dir;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    calc(r, c, dir);
    cout << ans;
    return 0;
}
