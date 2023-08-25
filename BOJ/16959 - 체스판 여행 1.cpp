//
//  16959 - 체스판 여행 1.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/19.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dxKnight[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dyKnight[] = {1, 2, 2, 1, -1, -2, -2, -1};

const int dxBishop[] = {1, 1, -1, -1};
const int dyBishop[] = {1, -1, -1, 1};

const int dxRook[] = {1, 0, -1, 0};
const int dyRook[] = {0, 1, 0, -1};

const int KNIGHT = 0, BISHOP = 1, ROOK = 2;

int N, ans = INT_MAX;
int board[11][11];
int dist[3][101][11][11];

queue<tuple<int, int, int, int>> q;

void input() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                for (int k = 0; k < 3; k++) {
                    dist[k][1][i][j] = 1;
                    q.push({ k, 1, i, j });
                }
            }
        }
    }
}

void BFS() {
    while(!q.empty()) {
        auto [piece, num, curX, curY] = q.front();
        q.pop();
        
        if (num == N * N) {
            ans = min(ans, dist[piece][num][curX][curY]);
        }
        
        for (int i = 0; i < 3; i++) {
            if (dist[i][num][curX][curY]) continue;
            dist[i][num][curX][curY] = dist[piece][num][curX][curY] + 1;
            q.push({i, num, curX, curY});
        }
        
        if (piece == KNIGHT) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = curX + dxKnight[dir];
                int ny = curY + dyKnight[dir];
                int nxNum = num;
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (board[nx][ny] == num + 1) {
                    nxNum++;
                }
                if (dist[KNIGHT][nxNum][nx][ny]) continue;
                
                dist[KNIGHT][nxNum][nx][ny] = dist[KNIGHT][num][curX][curY] + 1;
                q.push({KNIGHT, nxNum, nx, ny});
            }
        }
        else if (piece == BISHOP) {
            for (int dir = 0; dir < 4; dir++) {
                for (int k = 1; k <= N; k++) {
                    int nx = curX + dxBishop[dir] * k;
                    int ny = curY + dyBishop[dir] * k;
                    int nxNum = num;
                    
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                    if (board[nx][ny] == num + 1) {
                        nxNum++;
                    }
                    if (dist[BISHOP][nxNum][nx][ny]) continue;
                    
                    dist[BISHOP][nxNum][nx][ny] = dist[BISHOP][num][curX][curY] + 1;
                    q.push({BISHOP, nxNum, nx, ny});
                }
            }
        }
        else if (piece == ROOK) {
            for (int dir = 0; dir < 4; dir++) {
                for (int k = 1; k <= N; k++) {
                    int nx = curX + dxRook[dir] * k;
                    int ny = curY + dyRook[dir] * k;
                    int nxNum = num;
                    
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                    if (board[nx][ny] == num + 1) {
                        nxNum++;
                    }
                    if (dist[ROOK][nxNum][nx][ny]) continue;
                    
                    dist[ROOK][nxNum][nx][ny] = dist[ROOK][num][curX][curY] + 1;
                    q.push({ROOK, nxNum, nx, ny});
                }
                
            }
        }
    }
}

int main() {
    FASTIO
    cin >> N;
    input();
    
    BFS();
    cout << ans - 1 << "\n";
    return 0;
}

/*
 크기가 N*N인 체스판, 각 칸에는 1 ~ N^2까지의 정수가 한 번씩 적혀있다. 지학이는 이 체스판을 이용해서 재미있는 게임을 해보려고 한다.
 가지고 있는 말은 나이트, 비숍, 룩이다. 가장 먼저 1 이 적혀있는 칸에 말 하나를 놓는다. 그 다음 1, 2, 3, ..., N^2 순서로 이동시키려고 한다.
 1초 동안 할 수 있는 행동은 체스판 위에 놓인 말을 이동시키거나, 다른 말로 바꾸는 것이다.
 걸리는 시간의 최솟값
 
 BFS를 돌려서 확인하는 풀이
 
 1 -> 2 -> 3 -> ... -> N^2에서 BFS를 이용하여 이동할 때 걸리는 최소 시간 구할 수 있다.
 BFS를 돌릴 때 방문 배열을 dist[말의 종류][현재까지 방문한 숫자][ROW][COL]을 선언하고 이를 BFS로 돌리게되면 현재까지 방문한 숫자가 N^2이 될 때 최솟값을 업데이트 시켜주는 방식으로 진행.
 
 */
