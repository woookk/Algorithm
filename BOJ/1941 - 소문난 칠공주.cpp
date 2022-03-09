//
//  1941 - 소문난 칠공주.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/08.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

string board[5];
bool student[25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

int main(){
    FASTIO;
    for(int i = 0; i < 5; i++){
        cin >> board[i];
    }
    fill(student + 7, student + 25, true);
    do {
        bool vis[5][5] = {}, select[5][5] = {};
        int dasom = 0, next = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < 25; i++){
            if(!student[i]){
                int x = i / 5, y = i % 5;
                select[x][y] = true;
                if(q.empty()){
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            next++;
            if(board[cur.X][cur.Y] == 'S') dasom++;
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if(vis[nx][ny] || !select[nx][ny]) continue;
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
        if(dasom >= 4 && next >= 7) ans++;
    } while(next_permutation(student, student + 25));
    cout << ans;
    return 0;
}
