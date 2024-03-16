//
//  11058 - 크리보드.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/16.
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
    vector<ll> dp(105);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    for (int i = 4; i <= N; i++) {
        for (int j = 3; j < i; j++) {
            dp[i] = max(dp[i], (j - 1) * dp[i - j]);
        }
    }
    cout << dp[N];
    return 0;
}
