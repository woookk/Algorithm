//
//  2225 - 합분해.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/25.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MOD = 1e9;

int N, K;

int main() {
    FASTIO
    cin >> N >> K;
    
    vector<vector<int>> dp(K + 1, vector<int> (N + 1, 0));
    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 0; i <= K; i++) {
        dp[i][1] = i;
    }
    
    for (int i = 1; i <= K; i++) {
        for (int j = 2; j <= N; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[K][N];
    return 0;
}

/*
 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
 덧셈의 순서가 바뀐 경우는 다른 경우로 센다.
 
 dp[i][j] = dp[i - 1][0] + ... + d[i - 1][j]의 점화식을 이용해서 풀이 가능
 또한 위 점화식의 관계를 이용하게 되면
 dp[i][j] = dp[i - 1][0] + ... + dp[i - 1][j]
 dp[i][j - 1] = dp[i - 1][0] + ... + dp[i - 1][j - 1]
 이므로 dp[i][j] = d[i][j - 1] + d[i - 1][j]를 이용하면 더 쉽게 풀이가 가능하다.
 */
