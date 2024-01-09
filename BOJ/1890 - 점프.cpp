//
//  1890 - 점프.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/09.
//

#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int N;

int main() {
    FASTIO
    cin >> N;
    vector<vector<int>> board(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<ll>> dp(N, vector<ll> (N, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!dp[i][j] || !board[i][j]) continue;
            int nx = i + board[i][j];
            int ny = j + board[i][j];
            if (nx < N) {
                dp[nx][j] += dp[i][j];
            }
            if (ny < N) {
                dp[i][ny] += dp[i][j];
            }
        }
    }
    cout << dp[N - 1][N - 1];
    return 0;
}

/*
 N * N 게임판에 수가 적혀져 있다. 이 게임의 목표는 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것이다.
 각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다. 반드시 오른쪽이나 아래쪽으로만 이동해야 한다.
 0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다.
 한 번 점프를 할 때, 방향을 바꾸면 안된다. 즉, 한 칸에서 오른쪽으로 점프를 하거나, 아래로 점프를 하는 두 가지 경우만 존재한다.
 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 가는 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램 작성
 
 현재 칸까지 이동할 수 있는 경로의 개수 배열을 이용해 다이나믹 프로그래밍 방식으로 풀이를 진행
 (0, 0)에서 시작해서 각 칸에 적혀있는 수만큼 이동할 수 있다면, 현재 칸까지의 경우의 수를 더해주는 방식
 */
