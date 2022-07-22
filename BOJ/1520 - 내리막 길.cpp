//
//  1520 - 내리막 길.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/22.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int M, N;
int board[501][501];
int d[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int func(int x, int y){
    if(d[x][y] != -1) return d[x][y];
    if(x == N - 1 && y == M - 1) return 1;
    d[x][y] = 0;
    for(int dir = 0; dir < 4; ++dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(board[x][y] > board[nx][ny]) d[x][y] += func(nx, ny);
    }
    return d[x][y];
}

int main(void){
    FASTIO
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            d[i][j] = -1;
        }
    }
    cout << func(0, 0);
    return 0;
}
