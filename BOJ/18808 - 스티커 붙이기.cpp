//
//  18808 - 스티커 붙이기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/14.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, K;
int R, C;
bool board[41][41];
bool sticker[10][10];

bool ispossible(int x, int y){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[x + i][y + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(sticker[i][j] == 1) board[x + i][y + j] = 1;
        }
    }
    return true;
}

void rotate(){
    int tmp[12][12];
    
    for(int i = 0 ; i < R; i++){
        for(int j = 0; j < C; j++){
            tmp[i][j] = sticker[i][j];
        }
    }
    
    for(int i = 0 ; i < C; i++){
        for(int j = 0; j < R; j++){
            sticker[i][j] = tmp[R - 1- j][i];
        }
    }
    swap(R, C);
}

int main(){
    FASTIO;
    cin >> N >> M >> K;
    while(K--){
        cin >> R >> C;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> sticker[i][j];
            }
        }
        for(int rot = 0; rot < 4; rot++){
            bool is_paste = false;
            for(int x = 0; x <= N - R; x++){
                if(is_paste) break;
                for(int y = 0; y <= M - C; y++){
                    if(ispossible(x, y)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate();
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ans += board[i][j];
        }
    }
    cout << ans;
    return 0;
}
