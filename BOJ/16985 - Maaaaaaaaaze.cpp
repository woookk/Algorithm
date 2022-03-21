//
//  16985 - Maaaaaaaaaze.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/21.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

bool board[4][5][5][5];
bool maze[5][5][5];
int ans = 125;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int BFS(){
    int dist[5][5][5] = {};
    if(maze[0][0][0] == 0 or maze [4][4][4] == 0) return 125;
    
    queue<tuple<int ,int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while(!q.empty()){
        int curX, curY, curZ;
        tie(curX, curY, curZ) = q.front();
        q.pop();
        for(int dir = 0; dir < 6; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
            if(nx == 4 && ny == 4 && nz == 4) return dist[curZ][curY][curX];
            if(!maze[nz][ny][nx]) continue;
            if(dist[nz][ny][nx]) continue;
            dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
            q.push({nx, ny, nz});
        }
    }
    return 125;
}

int main(){
    FASTIO;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                cin >> board[0][i][j][k];
            }
        }
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                board[1][i][j][k] = board[0][i][4-k][j];
            }
        }
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                board[2][i][j][k] = board[1][i][4-k][j];
            }
        }
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                board[3][i][j][k] = board[2][i][4-k][j];
            }
        }
    }
    
    int order[5] = {0, 1, 2, 3, 4};
    do {
        for(int tmp = 0; tmp < (1 << 10); tmp++){
            int brute = tmp;
            for(int i = 0; i < 5; i++){
                int dir = brute % 4;
                brute /= 4;
                for(int j = 0; j < 5; j++){
                    for(int k = 0; k < 5; k++){
                        maze[i][j][k] = board[dir][order[i]][j][k];
                    }
                }
            }
            ans = min(ans, BFS());
        }
    }
    while(next_permutation(order, order + 5));
    if(ans == 125) cout << -1;
    else cout << ans;
    return 0;
}
