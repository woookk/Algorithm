//
//  14502 - 연구소.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/11.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int board[10][10];
int board_copy[10][10];
bool vis[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, MX;


pair<int, int> wall[3];
vector<pair<int, int>> v;
vector<pair<int, int>> virus;

int BFS(){
    for(int i = 0; i < N; i++)
        fill(vis[i], vis[i]+M, 0);
    
    queue<pair<int, int>> q;
    for(auto c: virus){
        q.push(c);
        vis[c.X][c.Y] = 1;
    }
        
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny]) continue;
            if(board_copy[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            board_copy[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board_copy[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void combination(int start, int depth){
    if(depth == 3){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                board_copy[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < 3; i++){
            board_copy[wall[i].X][wall[i].Y] = 1;
        }
        MX = max(MX, BFS());
        return;
    }
    for(int i = start; i < v.size(); i++){
        wall[depth] = v[i];
        combination(i + 1, depth + 1);
    }
}

int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) {
                virus.push_back({i, j});
            }
            if(board[i][j] == 0) v.push_back({i, j});
        }
    }
    combination(0, 0);
    cout << MX;
}
