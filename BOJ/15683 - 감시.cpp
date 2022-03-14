//
//  15683 - 감시.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
int board[10][10];
int board_copy[10][10];
vector<pair<int, int>> cctv;

bool OOB(int a, int b){ // Out Of Bounds
    return a < 0 || a >= N || b < 0 || b >= M;
}

void upd(int x, int y, int dir){
  dir %= 4;
  while(1){
    x += dx[dir];
    y += dy[dir];
    if(OOB(x,y) || board_copy[x][y] == 6) return;
    if(board_copy[x][y] != 0) continue;
    board_copy[x][y] = 7;
  }
}

int main(){
    FASTIO;
    cin >> N >> M;
    int MN = 0;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6){
                cctv.push_back({i, j});
            }
            if(board[i][j] == 0) MN++;
        }
    }
    for(int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                board_copy[i][j] = board[i][j];
            }
        }
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++){
              int dir = brute % 4;
              brute /= 4;
              int x = cctv[i].X;
              int y = cctv[i].Y;
              if(board[x][y] == 1){
                upd(x,y,dir);
              }
              else if(board[x][y] == 2){
                upd(x,y,dir);
                upd(x,y,dir+2);
              }
              else if(board[x][y] == 3){
                upd(x,y,dir);
                upd(x,y,dir+1);
              }
              else if(board[x][y] == 4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
              }
              else{ // board1[x][y] == 5
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
              }
        }
        int val = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!board_copy[i][j]) val++;
            }
        }
        MN = min(MN, val);
    }
    cout << MN;
    return 0;
}
