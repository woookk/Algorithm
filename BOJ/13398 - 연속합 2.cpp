//
//  13398 - 연속합 2.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, ans;

int main() {
    FASTIO
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = arr[0];
    dp[1][0] = 0;
    ans = dp[0][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
        ans = max(ans, max(dp[0][i], dp[1][i]));
    }
    cout << ans;
    return 0;
}

/*
 n개의 정수로 이루어진 임의의 수열에서 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. (단, 수는 한개 이상 선택)
 또, 수열에서 수를 하나 제거할 수 있다. (제거하지 않아도 된다.)
 
 다이나믹 프로그래밍을 이용한 풀이 진행
 
 수를 제거하지 않고 연속합의 최댓값을 구하는 경우와 수를 제거하고 연속합의 최댓값을 구하는 경우로 나누어 생각
    수를 제거하지 않고 연속합의 최댓갑을 구하는 경우에는, dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i])
    수를 제거하고 연속합의 최댓값을 구하는 경우에는, dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i])
 */
