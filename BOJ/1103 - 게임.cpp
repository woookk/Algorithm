//
//  1103 - 게임.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/05.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, M;

int solve(vector<vector<int>>& board, vector<vector<int>>& dp, vector<vector<bool>>& visited, int curX, int curY) {
    if (curX < 0 || curY < 0 || curX >= N || curY >= M || board[curX][curY] == -1) {
        return 0;
    }
    
    if (visited[curX][curY]) {
        cout << -1 << "\n";
        exit(0);
    }
    
    if (dp[curX][curY] != -1) return dp[curX][curY];
    
    visited[curX][curY] = true;
    dp[curX][curY] = 0;
    int product = board[curX][curY];
    for (int dir = 0; dir < 4; dir++) {
        int nx = curX + dx[dir] * product;
        int ny = curY + dy[dir] * product;
        dp[curX][curY] = max(dp[curX][curY], solve(board, dp, visited, nx, ny) + 1);
    }
    visited[curX][curY] = false;
    return dp[curX][curY];
}

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'H') {
                board[i][j] = -1;
            }
            else {
                board[i][j] = c - '0';
            }
        }
    }
    vector<vector<int>> dp(N, vector<int>(M, -1));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    cout << solve(board, dp, visited, 0, 0) << "\n";
    return 0;
}

/*
 1 ~ 9까지의 숫자와, 구멍이 있는 직사각형 보드에서 게임을 한다.
 보드의 가장 왼쪽 위에 동전을 하나 올려놓고 다음과 같이 동전을 움직인다.
 1. 동전이 있는 곳에 쓰여진 숫자 X를 본다.
 2. 위, 아래, 왼쪽, 오른쪽 방향 중에 한 가지를 고른다.
 3. 동전을 고른 방향으로 X만큼 움직인다. 이 때, 중간에 있는 구멍은 무시한다.
 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 게임은 종료된다. 보드의 상태가 주어졌을 때, 최대 몇 번의 동전을 움직일 수 있는지 구하는 프로그램을 작성
 
 다이나믹 프로그래밍을 활용하여 풀이 진행
 */
