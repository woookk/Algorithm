//
//  17070 - 파이프 옮기기 1.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/01.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

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
    
    vector<vector<vector<int>>> dp(3, vector<vector<int>>(N, vector<int> (N, 0)));
    dp[0][0][1] = 1;
    for (int i = 2; i < N; i++) {
        if (board[0][i]) continue;
        dp[0][0][i] = dp[0][0][i - 1];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (board[i][j]) continue;
            dp[0][i][j] = dp[0][i][j - 1] + dp[1][i][j - 1];
            dp[2][i][j] = dp[2][i - 1][j] + dp[1][i - 1][j];
            if (board[i - 1][j] || board[i][j - 1]) continue;
            dp[1][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
        }
    }
    cout << dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1];
    return 0;
}

/*
 집 수리를 위해서 파이프 하나를 옮기려고 한다.
 파이프는 매우 무겁기 때문에, 파이프를 밀어서 이동시키려고 한다. 벽에는 새로운 벽지를 발랐기 때문에, 파이프가 벽을 긁으면 안 된다. 즉, 파이프는 항상 빈 칸만 차지해야 한다.
 파이프를 밀 수 있는 방향은 총 3가지가 있으며, →, ↘, ↓ 방향이다. 파이프는 밀면서 회전시킬 수 있다. 회전은 45도만 회전시킬 수 있으며, 미는 방향은 오른쪽, 아래, 또는 오른쪽 아래 대각선 방향이어야 한다.
 파이프가 가로로 놓여진 경우에 가능한 이동 방법은 총 2가지, 세로로 놓여진 경우에는 2가지, 대각선 방향으로 놓여진 경우에는 3가지가 있다.
 가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.
 
 파이프의 한쪽 끝이 (i, j)로 이동시키는 방법의 개수 파이프의 방향(가로 0, 대각선 1, 세로 2)에 따라서 dp 3차원 배열을 선언한 후
 다이나믹 프로그래밍을 이용하여 각각의 위치별로 이동시키는 방법의 개수를 구하는 방식으로 풀이
 */
