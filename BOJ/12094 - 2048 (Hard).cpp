//
//  12094 - 2048 (Hard).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/16.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, ans;
int board[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board_tot;

void move(int depth, int max_depth, int dir){
    if(2 * ans > board_tot) return;
    if(depth == max_depth) return;
    int copy_board[21][21];
    int copy_comp_num = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            copy_board[i][j] = board[i][j];
            if(copy_board[i][j] != 0) copy_comp_num++;
            board[i][j] = 0;
        }
    }
    
    if(dir == 0){
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
                board[i][j] = moved[j];
            }
        }
    }
    else if(dir == 1){
        for(int i = 0; i < N; i++){
            int moved[21] = {};
            int idx = N - 1;
            for(int j = N - 1; j >= 0; j--){
                if(copy_board[i][j] == 0) continue;
                if(moved[idx] == 0)
                    moved[idx] = copy_board[i][j];
                else if(moved[idx] == copy_board[i][j]) moved[idx--] *= 2;
                else moved[--idx] = copy_board[i][j];
            }
            for(int j = N - 1; j >= 0; j--){
                board[i][j] = moved[j];
            }
        }
    }
    else if(dir == 2){
        for(int i = 0; i < N; i++){
            int moved[21] = {};
            int idx = 0;
            for(int j = 0; j < N; j++){
                if(copy_board[j][i] == 0) continue;
                if(moved[idx] == 0)
                    moved[idx] = copy_board[j][i];
                else if(moved[idx] == copy_board[j][i]) moved[idx++] *= 2;
                else moved[++idx] = copy_board[j][i];
            }
            for(int j = 0; j < N; j++){
                board[j][i] = moved[j];
            }
        }
    }
    else {
        for(int i = 0; i < N; i++){
            int moved[21] = {};
            int idx = N - 1;
            for(int j = N - 1; j >= 0; j--){
                if(copy_board[j][i] == 0) continue;
                if(moved[idx] == 0)
                    moved[idx] = copy_board[j][i];
                else if(moved[idx] == copy_board[j][i]) moved[idx--] *= 2;
                else moved[--idx] = copy_board[j][i];
            }
            for(int j = N - 1; j >= 0; j--){
                board[j][i] = moved[j];
            }
        }
    }

    int cur_MX = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cur_MX = max(cur_MX, board[i][j]);
        }
    }
    ans = max(cur_MX, ans);
    if (cur_MX << (max_depth - depth - 1) <= ans) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                board[i][j] = copy_board[i][j];
            }
        }
        return;
    }
    bool isChanged = false;
    int comp_num = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] != copy_board[i][j]) isChanged = true;
            if(board[i][j] != 0) comp_num++;
        }
    }
    if (isChanged) {
        if (copy_comp_num == comp_num) {
            for(int nxdir = 0; nxdir < 4; nxdir++){
                if(dir == nxdir) continue;
                move(depth + 1, max_depth, nxdir);
            }
        }
        else {
            for(int nxdir = 0; nxdir < 4; nxdir++){
                move(depth + 1, max_depth, nxdir);
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = copy_board[i][j];
        }
    }
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            board_tot += board[i][j];
        }
    }
    for(int dir = 0; dir < 4; dir++){
        move(0, 10, dir);
    }
    cout << ans;
    return 0;
}
