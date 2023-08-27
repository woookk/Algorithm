//
//  16952 - 체스판 여행 2.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MAX 10 + 1

int n;
int map[MAX][MAX];
queue<tuple<int, int, int, int>> q;
pair<int, int> visited[MAX][MAX][101][3];

const int dxKnight[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dyKnight[] = {1, 2, 2, 1, -1, -2, -2, -1};

const int dxBishop[] = {1, 1, -1, -1};
const int dyBishop[] = {1, -1, -1, 1};

const int dxRook[] = {1, 0, -1, 0};
const int dyRook[] = {0, 1, 0, -1};

int resTime = INT_MAX, resChange = INT_MAX;
pair<int, int> ans = {-1, -1};

bool isRange(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n) return false;
    return true;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1) {
                for (int k = 0; k < 3; k++) {
                    q.push({ i, j, k, 1 });
                    visited[i][j][1][k] = {0, 0};
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < 101; k++) {
                for (int l = 0; l < 3; l++) {
                    visited[i][j][k][l] = {-1, -1};
                }
            }
        }
    }
}

pair<int, int> bfs() {

    while (!q.empty()) {
        auto [curY, curX, curKind, curNum] = q.front();

        q.pop();
        auto p = visited[curY][curX][curNum][curKind];
        if (curNum == n * n) {
            if (ans.first == -1 || ans > p) {
                ans = p;
            }
        }

        switch (curKind) {
        case 0:
            for (int dir = 0; dir < 8; dir++) {
                int nx = curX + dxKnight[dir];
                int ny = curY + dyKnight[dir];
                int kind = curKind;
                int num = curNum;

                if (!isRange(ny, nx)) continue;
                if (map[ny][nx] == num + 1) {
                    num++;
                }
                auto np = make_pair(p.first + 1, p.second);
                if ((visited[ny][nx][num][kind]).first != -1 &&
                    (visited[ny][nx][num][kind] <= np)) continue;

                visited[ny][nx][num][kind] = np;
                q.push({ ny, nx, kind, num});
            }
            break;

        case 1:
            for (int dir = 0; dir < 4; dir++) {
                int ny = curY;
                int nx = curX;

                while (1) {
                    ny += dyBishop[dir];
                    nx += dxBishop[dir];
                    int kind = curKind;
                    int num = curNum;

                    if (!isRange(ny, nx)) break;
                    if (map[ny][nx] == num + 1) {
                        num++;
                    }
                    auto np = make_pair(p.first + 1, p.second);
                    if ((visited[ny][nx][num][kind]).first != -1 &&
                        (visited[ny][nx][num][kind] <= np)) continue;

                    visited[ny][nx][num][kind] = np;
                    q.push({ ny, nx, kind, num });
                }
            }
            break;

        case 2:
            for (int dir = 0; dir < 4; dir++) {
                int ny = curY;
                int nx = curX;

                while (1) {
                    ny += dyRook[dir];
                    nx += dxRook[dir];
                    int kind = curKind;
                    int num = curNum;

                    if (!isRange(ny, nx)) break;
                    if (map[ny][nx] == num + 1) {
                        num++;
                    }
                    auto np = make_pair(p.first + 1, p.second);
                    if ((visited[ny][nx][num][kind]).first != -1 &&
                        (visited[ny][nx][num][kind] <= np)) continue;

                    visited[ny][nx][num][kind] = np;
                    q.push({ ny, nx, kind, num });
                }
            }
            break;
        }

        for (int k = 0; k < 3; k++) {
            int ny = curY;
            int nx = curX;
            int kind = curKind;
            int num = curNum;

            if (k == kind) continue;
            kind = k;

            auto np = make_pair(p.first + 1, p.second + 1);
            if ((visited[ny][nx][num][kind]).first != -1 &&
                (visited[ny][nx][num][kind] <= np)) continue;

            visited[ny][nx][num][kind] = np;
            q.push({ ny, nx, kind, num });
        }

    }
    return ans;
}

int main() {
    FASTIO
    init();
    input();
    auto ans = bfs();
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}

/*
 크기가 N*N인 체스판, 각 칸에는 1 ~ N^2까지의 정수가 한 번씩 적혀있다. 지학이는 이 체스판을 이용해서 재미있는 게임을 해보려고 한다.
 가지고 있는 말은 나이트, 비숍, 룩이다. 가장 먼저 1 이 적혀있는 칸에 말 하나를 놓는다. 그 다음 1, 2, 3, ..., N^2 순서로 이동시키려고 한다.
 1초 동안 할 수 있는 행동은 체스판 위에 놓인 말을 이동시키거나, 다른 말로 바꾸는 것이다.
 걸리는 시간의 최솟값
 최소 시간이 나오는 방법이 여러 가지인 경우에는 말을 바꾸는 횟수를 최소로 하는 경우.
 
 BFS를 돌려서 확인하는 풀이.
 
 1 -> 2 -> 3 -> ... -> N^2에서 BFS를 이용하여 이동할 때 걸리는 최소 시간 구할 수 있다.
 BFS를 돌릴 때 방문 배열을 dist[말의 종류][현재까지 방문한 숫자][ROW][COL]을 선언하고 이를 BFS로 돌리게되면 현재까지 방문한 숫자가 N^2이 될 때 최솟값을 업데이트 시켜주는 방식으로 진행.
 -> 방문 배열에서 최소 시간과 변경횟수 저장한 후 최소 횟수가 더 작은 경우 업데이트.
 
 */
