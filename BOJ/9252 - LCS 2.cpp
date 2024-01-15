//
//  9252 - LCS 2.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string a, b;
string ans;

int main() {
    FASTIO
    cin >> a >> b;
    
    int lenA = (int) a.length(), lenB = (int) b.length();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    while (dp[lenA][lenB]) {
        if (dp[lenA][lenB] == dp[lenA - 1][lenB]) {
            lenA--;
        }
        else if (dp[lenA][lenB] == dp[lenA][lenB - 1]) {
            lenB--;
        }
        else {
            ans += a[lenA - 1];
            lenA--;
            lenB--;
        }
    }
    cout << dp[a.length()][b.length()] << "\n";
    if (ans.length()) {
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}

/*
 LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
 두 문자열이 주어졌을 때 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력하는 프로그램을 작성
 
 LCS의 길이는 다이나믹 프로그래밍을 이용하여 구할 수 있고, 이 때 각각의 인덱스 별로 주어진 LCS의 길이를 이용해서 LCS를 역추적하는 방식으로 풀이를 진행하였다.
 */
