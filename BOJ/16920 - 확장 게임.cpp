//
//  16920 - 확장 게임.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/09.
//

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, P;
string board[1001];
int canExtend[1001][1001];
int S[10];
int area[10];
queue<tuple<int, int, int>> q[10];

int main(){
    FASTIO;
    cin >> N >> M >> P;
    for(int i = 1; i <= P; i++)
        cin >> S[i];
    char c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> c;
            if(c =='.') canExtend[i][j] = 1;
            else if(c =='#') canExtend[i][j] = 0;
            else{
                canExtend[i][j] = 0;
                q[c-'0'].push({i, j, 0});
                area[c-'0'] += 1;
            }
        }
    }
    while(1){
        bool flag = 0;
        for(int i = 1; i <= P; i++){
            queue<tuple<int, int, int>> nextq;
            while(!q[i].empty()){
                int curX, curY, curstep;
                tie(curX, curY, curstep) = q[i].front();
                q[i].pop();
                if(curstep >= S[i]){
                    nextq.push({curX, curY, 0});
                    continue;
                }
                for(int dir = 0; dir < 4; dir++){
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if(!canExtend[nx][ny]) continue;
                    q[i].push({nx,ny, curstep+1});
                    canExtend[nx][ny] = 0;
                    area[i]++;
                    flag = 1;
                }
            }
            q[i] = nextq;
        }
        if(!flag) break;
    }
    for(int i = 1; i <=P; i++){
        cout << area[i] << " ";
    }
    return 0;
}
