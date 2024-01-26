//
//  1102 - 발전소.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/26.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX;

int N, P;
int ans;

int countBits(int bit) {
    int result = 0;
    while (bit != 0) {
        result += (bit & 1);
        bit /= 2;
    }
    return result;
}

int solve(vector<vector<int>> &board, vector<int> &dp, int status) {
    int cnt = countBits(status);
    if (cnt >= P) {
        return 0;
    }
    
    if (dp[status] != -1) return dp[status];
    dp[status] = INF;
    
    for (int i = 0; i < N; i++) {
        if (!(status & (1 << i))) continue;
        for (int j = 0; j < N; j++) {
            if (status & (1 << j)) continue;
            dp[status] = min(dp[status], solve(board, dp, status | (1 << j)) + board[i][j]);
        }
    }
    return dp[status];
}

int main() {
    FASTIO
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    string s;
    cin >> s;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'Y') {
            start |= (1 << i);
        }
    }
    cin >> P;
    
    vector<int> dp((1 << N), -1);
    ans = solve(board, dp, start);
    
    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}

/*
 회사에서 잠깐 잘 때마다, 몇몇 발전소가 고장이 난다.
 발전소를 고치는 방법은 간단하다. 고장나지 않은 발전소를 이용하여 고장난 발전소를 재시작하면 된다. 하지만, 이 때 비용이 발생한다.
 이 비용은 어떤 발전소에서 어떤 발전소를 재시작하느냐에 따라 다르다.
 적어도 P개의 발전소가 고장나 있지 않도록, 발전소를 고치는 비용의 최솟값을 구하는 프로그램을 작성
 
 발전소의 상태를 비트마스킹을 이용하여 표현한 후,
 현재 상태에서 발전소를 고치는 비용은
    고장난 발전소 하나를 고칠 때 드는 비용 + 해당 발전소가 고쳐진 상태에서 발전소를 고치는데 드는 비용의 합으로 구할 수 있다.
 점화식으로 나타내면 dp[status] = dp[status | (1 << j) + board[i][j]; (i는 정상적인 발전소, j가 고장난 발전소일 때)
 
 재귀와 다이나믹 프로그래밍 방식을 이용하여 풀이 진행
 */
