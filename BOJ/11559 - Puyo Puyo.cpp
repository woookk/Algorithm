//
//  11559 - Puyo Puyo.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/16.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
const int board_row = 12;
const int board_col = 6;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[board_row];

int ans;
bool vis[board_row][board_col];
bool isChanged = true;

int main(){
    FASTIO;
    for(int i = 0; i < board_row; i++)
        cin >> board[i];
    while(isChanged){
        isChanged = false;
        for(int i = 0; i < board_row; i++){
            for(int j = 0; j < board_col; j++){
                queue<pair<int ,int>> q;
                vector<pair<int, int>> v;
                if(board[i][j] != '.' && !vis[i][j]){
                    q.push({i, j});
                    vis[i][j] = 1;
                    v.push_back({i, j});
                }
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= board_row || ny >= board_col) continue;
                        if(vis[nx][ny]) continue;
                        if(board[nx][ny] != board[i][j]) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        v.push_back({nx, ny});
                    }
                }
                if(v.size() >= 4){
                    isChanged = true;
                    for(auto cur : v){
                        board[cur.X][cur.Y] = '.';
                    }
                }
            }
        }
        for(int i = 0; i < board_col; i++){
            char moved[board_row] = {'.'};
            int idx = board_row - 1;
            for(int j = board_row -1; j >= 0; j--){
                if(board[j][i] == '.') continue;
                moved[idx--] = board[j][i];
            }
            while(idx > 0){
                moved[idx--] = '.';
            }
            for(int j = board_row -1; j >= 0; j--){
                board[j][i] = moved[j];
            }
        }
        if(isChanged)ans++;
        for(int i = 0; i < board_row; i++){
            fill(vis[i], vis[i] + board_col, 0);
        }
    }
    cout << ans;
    return 0;
}
