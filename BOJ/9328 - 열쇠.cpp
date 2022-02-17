//
//  9328 - 열쇠.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/16.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[102][102];
int vis[102][102];

int main(){
    FASTIO;
    int TC;
    cin >> TC;
    while(TC--){
        int h, w;
        cin >> h >> w;
        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26];
        bool key[26] = {};
        int cnt = 0;
        for(int i = 0; i <= h + 1; i++){
            fill(board[i], board[i] + w + 2, 0);
            fill(vis[i], vis[i] + w + 2, 0);
        }
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> board[i][j];
            }
        }
        string tmp;
        cin >> tmp;
        for(char c : tmp){
            if(c != '0')
                key[c-'a'] = 1;
        }
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
                if(board[nx][ny] == '*' || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z'){
                    int num = board[nx][ny] + 32 -'a';
                    if(!key[num]){
                        door[num].push({nx, ny});
                        continue;
                    }
                }
                else if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z'){
                    int num = board[nx][ny] - 'a';
                    key[num] = 1;
                    while(!door[num].empty()){
                        auto ndoor = door[num].front();
                        door[num].pop();
                        q.push({ndoor.X, ndoor.Y});
                    }
                }
                else if(board[nx][ny] == '$') cnt++;
                q.push({nx,ny});
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
