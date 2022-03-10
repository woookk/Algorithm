//
//  18809 - Gaaaaaaaaaarden.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M, G, R, MX;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[51][51];
vector<pair<int, int>> st;
int st_size;
int isused[10];

const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int func(){
    int cnt = 0;
    queue<pair<int, int>> q;
    pair<int, int> state[51][51];
    for(int i = 0; i < st_size; i++){
        if(isused[i] == GREEN || isused[i] == RED){
            state[st[i].X][st[i].Y] = {0, isused[i]};
            q.push(st[i]);
        }
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int curTime = state[cur.X][cur.Y].X;
        int curColor = state[cur.X][cur.Y].Y;
        if(state[cur.X][cur.Y].Y == FLOWER) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(!board[nx][ny]) continue;
            if(state[nx][ny].Y == FLOWER) continue;
            else if(state[nx][ny].Y == RED){
                if(curColor == GREEN && state[nx][ny].X == curTime + 1){
                    cnt++;
                    state[nx][ny].Y = FLOWER;
                }
            }
            else if(state[nx][ny].Y == GREEN){
                if(curColor == RED && state[nx][ny].X == curTime + 1){
                    cnt++;
                    state[nx][ny].Y = FLOWER;
                }
            }
            else {
                state[nx][ny] = {curTime + 1, curColor};
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}
int main(){
    FASTIO;
    cin >> N >> M >> G >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) st.push_back({i, j});
        }
    }
    st_size = (int)st.size();
    fill(isused + st_size - R - G, isused + st_size - R, GREEN);
    fill(isused + st_size - R, isused + st_size, RED);
    int MX = 0;
    do{
        MX = max(MX, func());
    }
    while(next_permutation(isused, isused + st_size));
    cout << MX;
    return 0;
}
