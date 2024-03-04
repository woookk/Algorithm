//
//  1562 - 계단 수.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/04.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MOD = 1e9;

int N, ans;

int main() {
    FASTIO
    cin >> N;
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(10, vector<int>(1 << 10, 0)));
    for (int i = 1; i < 10; i++) {
        dp[1][i][1 << i] = 1;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < (1 << 10); k++) {
                if (j < 9) {
                    int bit = k | (1 << (j + 1));
                    dp[(i + 1)][j + 1][bit] += dp[i][j][k];
                    dp[(i + 1)][j + 1][bit] %= MOD;
                }
                if (j > 0) {
                    int bit = k | (1 << (j - 1));
                    dp[(i + 1)][j - 1][bit] += dp[i][j][k];
                    dp[(i + 1)][j - 1][bit] %= MOD;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += dp[N][i][1023];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}

/*
 인접한 모든 자리의 차이가 1인 수를 계단 수라고 한다.
 N이 주어질 때, 길이가 N이면서 0부터 9까지의 숫자가 모두 등장하는 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성
 
 **핵심 아이디어 10개의 숫자가 각각 사용되었는지를 비트마스킹을 이용하여 저장한다**
 
 dp[길이 + 1][마지막 숫자 + 1 / - 1][등장한 숫자들의 비트값 | (마지막 숫자 + 1 / - 1)] = dp[길이][마지막 숫자][등장한 숫자들의 비트값] 점화식을 이용해서 길이에 따른 계단 수를 모두 구할 수 있다.
 이 때, 등장한 숫자들의 비트값이 1023인 경우에만 숫자가 모두 등장하는 경우의 수의 답이 될 수 있다. 
 */
