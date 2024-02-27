//
//  20058 - 마법사 상어와 파이어스톰.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, Q;
int remain, biggest;

void rotate(vector<vector<int>>& nxBoard, vector<vector<int>>& board, int row, int col, int len) {
    if (len <= 1) return;
    
    for (int i = 0; i < len; i++) {
        nxBoard[row][col + i] = board[row + len - 1 - i][col];
        nxBoard[row + i][col] = board[row + len - 1][col + i];
        nxBoard[row + i][col + len - 1] = board[row][col + i];
        nxBoard[row + len - 1][col + i] = board[row + len - 1 - i][col + len - 1];
    }
    rotate(nxBoard, board, row + 1, col + 1, len - 2);
}

void decrease(vector<vector<int>>& nxBoard, vector<vector<int>>& board) {
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            if (board[i][j] == 0) continue;
            int around = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= (1 << N) || ny >= (1 << N)) continue;
                if (board[nx][ny]) around++;
            }
            if (around < 3) {
                nxBoard[i][j]--;
            }
        }
    }
}

void firestorm(vector<vector<int>>& board, int L) {
    vector<vector<int>> nxBoard = board;
    int len = (1 << L);
    for (int i = 0; i < (1 << N); i += len) {
        for (int j = 0; j < (1 << N); j += len) {
            rotate(nxBoard, board, i, j, len);
        }
    }
    board = nxBoard;
    decrease(nxBoard, board);
    board = nxBoard;
}

void BFS(vector<vector<int>>& board, vector<vector<bool>>& visited, int curX, int curY) {
    int area = 0;
    queue<pair<int, int>> q;
    q.push({curX, curY});
    visited[curX][curY] = true;
    remain += board[curX][curY];
    area++;
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= (1 << N) || ny >= (1 << N)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 0) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
            area++;
            remain += board[nx][ny];
        }
    }
    biggest = max(biggest, area);
}

int main() {
    FASTIO
    cin >> N >> Q;
    vector<vector<int>> board(1 << N, vector<int>(1 << N));
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        int L;
        cin >> L;
        firestorm(board, L);
    }
    
    vector<vector<bool>> visited(1 << N, vector<bool>(1 << N, false));
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            if (board[i][j] == 0 || visited[i][j]) continue;
            BFS(board, visited, i, j);
        }
    }
    cout << remain << "\n" << biggest;
    return 0;
}

/*
 마법사 상어는 파이어볼과 토네이도를 조합해 파이어스톰을 시전할 수 있다. 파이어스톰을 크기가 2^N * 2^N인 격자로 나누어진 얼음판에서 연습하려고 한다.
 파이어스톰을 시전하려면 시전할 때마다 단계 L을 결정해야 한다. 파이어스톰은 먼저 격자를 2^L * 2^L 크기의 부분 격자로 나눈다. 그 후, 모든 부분 격자를 시계 방향으로 90도 회전시킨다.
 이후 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1개 줄어든다.
 
 마법사 상어는 파이어스톰을 총 Q번 시전하려고 한다. 모든 파이어스톰을 시전한 후,
 1. 남아있는 얼음의 합
 2. 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
 를 구해는 프로그램을 작성
 
 격자를 2^L * 2^L 크기의 부분 격자로 나누고 돌리는 부분을 재귀 함수를 이용하여 구현
 가장 바깥 쪽 테두리를 먼저 돌린 후 안 쪽 테두리를 순차적으로 호출하는 방식
 */
