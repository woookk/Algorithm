//
//  2589 - 보물섬.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/02.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int R, C, ans;
char map[51][51];
int dist[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    for(int i = 0; i < R; i++){
        fill(dist[i], dist[i] + C, 0);
    }
    dist[x][y] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(map[nx][ny] == 'W') continue;
            if(dist[nx][ny] > 0) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    for(int i = 0; i < R; i++){
        ans = max(ans, *max_element(dist[i], dist[i] + C) - 1);
    }
}

int main(){
    FASTIO
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] == 'L'){
                BFS(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}
