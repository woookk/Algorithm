//
//  9376 - 탈옥.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/08.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int INF = 10005;

int TC;
int h, w, ans;

char map[105][105];
int openCount[3][105][105];
pair<int, int> person[3];

void input() {
    cin >> h >> w;
    person[0] = { -1, -1 };
    person[1] = { -1, -1 };
    person[2] = { 0, 0 };
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            if (i == 0 || j == 0 || i == h + 1 || j == w + 1) {
                map[i][j] = '.';
            }
            else {
                cin >> map[i][j];
            }
            
            if (map[i][j] == '$') {
                if (person[0].first == -1) {
                    person[0] = { i, j };
                }
                else {
                    person[1] = { i, j };
                }
            }
        }
    }
    
    for (int idx = 0; idx < 3; idx++) {
        for (int i = 0; i < 105; i++) {
            fill(openCount[idx][i], openCount[idx][i] + 105, INF);
        }
    }
}

void BFS(int idx) {
    queue<tuple<int, int, int>> q;
    
    int x = person[idx].first, y = person[idx].second;
    q.push({ 1, x, y });
    openCount[idx][x][y] = 1;
    
    while (!q.empty()) {
        auto [curCnt, curX, curY] = q.front();
        q.pop();
        
        
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nxCnt = curCnt;
        
            if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
            if (map[nx][ny] == '*') continue;
            if (map[nx][ny] == '#') nxCnt++;
            if (openCount[idx][nx][ny] > nxCnt) {
                openCount[idx][nx][ny] = nxCnt;
                q.push({nxCnt, nx, ny});
            }
        }
        
    }
    
    
    
}

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        input();
        for (int idx = 0; idx < 3; idx++) {
            BFS(idx);
        }
        
        ans = INF;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == '*') continue;
                if (openCount[0][i][j] == INF || openCount[1][i][j] == INF || openCount[2][i][j] == INF) continue;
                
                int sum = 0;
                for (int idx = 0; idx < 3; idx++) {
                    sum += openCount[idx][i][j];
                }
                if (map[i][j] == '#') {
                    sum -= 2;
                }
                ans = min(ans, sum - 3);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
 죄수 두 명을 탈옥시켜야 한다. 감옥은 1층짜리 건물이고, 상근이는 방금 평면도를 얻었다.
 평면도에는 모든 벽과 문이 나타나 있고, 탈옥시켜야 하는 죄수의 위치도 나타나 있다. 감옥은 무인 감옥으로 죄수 두 명이 감옥에 있는 유일한 사람이다.
 문은 중앙 제어실에서만 열 수 있다. -> 특별한 기술을 이용해 제어실을 통하지 않고 문을 열려고 한다.
 두 죄수를 탈옥시키기 위해서 열어야 하는 문의 개수를 구하는 프로그램을 작성하시오.
 
 상근이, 두 죄수의 위치에서 각각 BFS를 통하여 연 문의 개수를 업데이트
 세 사람이 모두 만나는 지점에서 각각 연 문의 개수를 더해주면서 만날 수 있는 모든 지점에서의 최솟값을 구한다.
 - 빈 공간에서 만날 때
 - 문에서 만날 때
 문에서 만날 때 세 사람 중 한 사람만 문을 열면 되므로 더한 문의 개수에서 2를 빼준다.
 빈 공간에서 만날 때 (두 죄수가 문에서 이미 만나고 빈 공간에서 만나는 경우는 문에서 만날 때에에서 계산)
 */
