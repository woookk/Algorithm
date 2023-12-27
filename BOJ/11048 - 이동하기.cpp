//
//  11048 - 이동하기.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/27.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<int>> board(N + 1, vector<int> (M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    
    vector<vector<int>> dp(N + 1, vector<int> (M + 1, 0));
    dp[1][1] = board[1][1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + board[i][j];
        }
    }
    cout << dp[N][M];
    return 0;
}

/*
 준규는 현재 (1, 1)에 있고, (N, M)으로 이동하려고 한다. 준규가 (r, c)에 있으면, (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있고, 각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다. 또, 미로 밖으로 나갈 수는 없다.
 준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최댓값을 구하시오.
 
 다이나믹 프로그래밍을 이용하여 왼쪽 위 대각선, 왼쪽, 오른쪽 위치까지의 최댓값 + 현재 위치의 사탕 개수를 더해서 dp 배열을 업데이트 해나가는 방식으로 풀이 진행
 */
