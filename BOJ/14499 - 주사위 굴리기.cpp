//
//  14499 - 주사위 굴리기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/19.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, x, y, K;
int board[21][21];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dice[7];

//  윗면이 2이고, 동쪽을 바라보는 방향이 6
//     [1]
//  [5][2][6]
//     [3]
//     [4]

int idx[4][4] = {
  {2,6,4,5}, // 동쪽, 5->2, 2->6, 6->4, 4->5
  {2,5,4,6}, // 서쪽, 6->2, 2->5, 5->4, 4->6
  {3,2,1,4}, // 북쪽, 4->3, 3->2, 2->1, 1->4
  {2,3,4,1}, // 남쪽, 1->2, 2->3, 3->4, 4->1
};

void roll(int dir){
    int tmp[7];
    for(int i = 1; i <= 6; i++) tmp[i] = dice[i];
    
    for(int i = 0; i < 4; i++){
        tmp[idx[dir][i]] = dice[idx[dir][(i + 1) % 4]];
    }
    
    for(int i = 1; i <= 6; ++i) dice[i]=tmp[i];
}

void move(int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
    x = nx; y = ny;
    roll(dir);
    if(board[nx][ny]){
        dice[4] = board[nx][ny];
        board[nx][ny] = 0;
    }
    else {
        board[nx][ny] = dice[4];
    }
    cout << dice[2] << "\n";
}

int main(){
    FASTIO;
    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int dir;
        cin >> dir;
        move(dir - 1);
    }
    return 0;
}
