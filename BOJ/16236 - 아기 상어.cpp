//
//  16236 - 아기 상어.cpp
//  cpp
//
//  Created by 민병욱 on 2023/11/28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
    
int N, ans;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.X == b.X) return a.Y < b.Y;
    return a.X < b.X;
}

int main() {
    FASTIO
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    queue<pair<int, int>> nxQ;
    int sharkSize = 2, remain = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                nxQ.push({i, j});
                board[i][j] = 0;
            }
        }
    }
    
    while (!nxQ.empty()) {
        auto cur = nxQ.front();
        nxQ.pop();
        
        vector<vector<int>> dist(N, vector<int>(N, -1));
        dist[cur.X][cur.Y] = 0;
        
        queue<pair<int, int>> curQ;
        curQ.push(cur);
        
        int shortest = 0;
        vector<pair<int, int>> candidate;
        while (!curQ.empty()) {
            auto [curX, curY] = curQ.front();
            curQ.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (dist[nx][ny] != -1) continue;
                if (sharkSize < board[nx][ny]) continue;
                if (board[nx][ny] != 0 && board[nx][ny] < sharkSize) {
                    if (shortest != 0 && shortest < dist[curX][curY] + 1) break;
                    candidate.push_back({nx, ny});
                    shortest = dist[curX][curY] + 1;
                }
                curQ.push({nx, ny});
                dist[nx][ny] = dist[curX][curY] + 1;
            }
        }

        sort(candidate.begin(), candidate.end(), cmp);
        if (candidate.size() > 0) {
            auto ate = candidate[0];
            nxQ.push(ate);
            board[ate.X][ate.Y] = 0;
            ans += dist[ate.X][ate.Y];
            remain--;
            if (remain == 0) {
                sharkSize++;
                remain = sharkSize;
            }
        }
    }
    cout << ans;
    return 0;
}

/*
 N * N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 존재
 아기 상어와 물고기는 모두 크기를 가지고 있고, 크기는 자연수이다. 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.
 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
 
 아기 상어가 어디로 이동할지 결정하는 방법
 - 더 이상 먹을 수 있는 물고기가 없다면 엄마 상어에게 도움을 요청
 - 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다
 - 먹을 수 있는 묵고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
    - 거리는 아기상어가 이동할 때 지나야하는 칸의 개수의 최솟값
    - 거리가 가까운 물고기가 많다면, 가장 위 -> 가장 왼쪽 순으로 이동한다.
 아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정할 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하시오.
 
 BFS를 진행할 때 dx, dy가 더해지는 방식으로만 우선순위를 따질 경우 잘못된 방문 순서가 발생할 수 있다. (왼쪽 아래에 있는 경우 > 같은 줄 오른쪽에 있는 경우)
 
 최단 거리로 도닳할 수 있는 목적지들 뽑고 가장 위, 그리고 가장 왼쪽에 있는 것으로 진행할 필요 있다.
 
 최단 거리로 도달할 수 있는 목적지들 후보 리스트에 넣은 후 가장 위, 왼쪽에 있는 것을 아기상어의 목적지로 수정하여 nxQ에 넣는 방식으로 BFS 여러 번 진행하여 풀이
 
 
 */
