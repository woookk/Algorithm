//
//  2407 - 조합.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/10.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m;
string ans;

int main() {
    FASTIO
    cin >> n >> m;
    vector<vector<string>> dp(n + 1, vector<string> (n + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = "1";
                continue;
            }
            int sum = 0;
            string a = dp[i - 1][j];
            string b = dp[i - 1][j - 1];

            while (!a.empty() || !b.empty() || sum) {
                if (!a.empty()) {
                    sum += a.back() - '0';
                    a.pop_back();
                }
                if (!b.empty()) {
                    sum += b.back() - '0';
                    b.pop_back();
                }
                dp[i][j].push_back((sum % 10) + '0');
                sum /= 10;
            }
            reverse(dp[i][j].begin(), dp[i][j].end());
        }
    }
    cout << dp[n][m];
    return 0;
}

/*
    nCm을 출력하는 프로그램 작성
    
    nCm = n-1Cm + n-1Cm-1이므로 이것을 이용해서 큰 수의 덧셈을 문자열 덧셈으로 직접 구현해서 풀이
 */
