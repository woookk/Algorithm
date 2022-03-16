//
//  12100 - 2048 (Easy).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/15.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, MX;
int board[21][21];
int copy_board[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rotate(){
    int tmp[21][21];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmp[i][j] = copy_board[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            copy_board[i][j] = tmp[N - 1 - j][i];
        }
    }
}

void move(int dir){
    while(dir--) rotate();
    for(int i = 0; i < N; i++){
        int moved[21] = {};
        int idx = 0;
        for(int j = 0; j < N; j++){
            if(copy_board[i][j] == 0) continue;
            if(moved[idx] == 0)
                moved[idx] = copy_board[i][j];
            else if(moved[idx] == copy_board[i][j]) moved[idx++] *= 2;
            else moved[++idx] = copy_board[i][j];
        }
        for(int j = 0; j < N; j++){
            copy_board[i][j] = moved[j];
        }
    }
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    for(int tmp = 0; tmp < (1 << 10); tmp++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                copy_board[i][j] = board[i][j];
            }
        }
        int dir = tmp;
        for(int i = 0; i < 5; i++){
            move(dir % 4);
            dir /= 4;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                MX = max(copy_board[i][j], MX);
            }
        }
    }
    cout << MX;
    return 0;
}
