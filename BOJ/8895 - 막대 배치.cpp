//
//  8895 - 막대 배치.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/25.
//

#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int T;

int main() {
    FASTIO
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>> (n + 1, vector<ll>(n + 1, 0)));
        dp[1][1][1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + (i - 2) * dp[i - 1][j][k];
                }
            }
        }
        cout << dp[n][l][r] << "\n";
    }
    return 0;
}

/*
 다이나믹 프로그래밍을 이용한 방식으로 풀이
 막대의 개수가 N - 1일 때, 건물의 개수가 N개가 되기 위해서 N - 1개의 막대보다 높이가 작은 막대를 하나 세운다고 생각
 왼쪽에서 봤을 때 L - 1, 오른쪽에서 봤을 때 R인 경우: 가장 왼쪽에 높이가 가장 작은 막대를 세운다.
 왼쪽에서 봤을 때 L, 오른쪽에서 봤을때 R - 1인 경우: 가장 오른쪽에 높이가 가장 작은 막대를 세운다.
 왼쪽에서 봤을 때 L, 오른쪽에서 봤을 때 R: N - 1개 건물 사이 N - 2개 위치 중 하나에 높이가 가장 작은 막대를 세운다.
 점화식으로 정의하면 dp[N][L][R] = dp[N - 1][L - 1][R] + dp[N - 1][L][R - 1] + (N - 2) * dp[N - 1][R][L]
 */
