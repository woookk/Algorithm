//
//  2248 - 이진수 찾기.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/12.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, L;
long long I;

int dp[35][35];
string ans;

void calc(int N, int L, long long I) {
    if (N == 0) return;
    if (L == 0) {
        for (int i = 0; i < N; i++) {
            ans += '0';
        }
        return;
    }
    
    long long count = 0;
    for (int i = 0; i <= L; i++) {
        count += dp[N - 1][i];
    }
    
    if (count >= I) {
        ans += '0';
        calc(N - 1, L, I);
    }
    else {
        ans += '1';
        calc(N - 1, L - 1, I - count);
    }
    return;
}

int main() {
    FASTIO
    cin >> N >> L >> I;
    
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    
    calc(N, L, I);
    cout << ans;
    return 0;
}

/*
    N자리 이진수. L개 이하 비트만 1인 것을 크기 순으로 나열했을 때, I번째 나오는 이진수를 구해내는 프로그램을 작성
    이진수는 0으로 시작할 수 있다.
    
    조합 성질을 이용한 다이나믹 프로그래밍으로 각각의 조합 구할 수 있다.
    
    5C3 + 5C2 + 5C1 + 5C0에서 구한 후
    5C3보다 I가 작을 경우 0으로 시작
    5C3보다 I가 클 경우 1로 시작
    이후 재귀를 이용하여 I번째인 이진수 구할 수 있다.
 */
