//
//  1309 - 동물원.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/28.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MOD = 9901;

int N;

int main() {
    FASTIO
    cin >> N;
    vector<vector<int>> dp(3, vector<int> (N));
    dp[0][0] = 1; dp[1][0] = 1; dp[2][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
        dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
    }
    cout << (dp[0][N - 1] + dp[1][N - 1] + dp[2][N - 1] ) % MOD;
    return 0;
}

/*
 어떤 동물원에 가로로 두칸 세로로 N칸인 우리가 있다.
 이 동물원에는 사자들이 살고 있는데 사자들을 우리에 가둘 때, 가로로도 세로로도 붙어 있게 배치할 수는 없다.
 2 * N 배열에 사자를 배치하는 경우의 수가 몇 가지인지 알아내는 프로그램을 작성
 
 각 행에서 사자가 존재하지 않을 때, 왼쪽 칸에 존재할 때, 그리고 오른쪽 칸에 존재할 때 세 가지로 구분하여 다이나믹 프로그래밍을 통해서 경우의 수 계산
 다음 행까지의 경우의 수는 이전 행에 어디에 사자가 있는지에만 영향을 받으므로
 */
