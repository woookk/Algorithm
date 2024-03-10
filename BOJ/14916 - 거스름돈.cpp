//
//  14916 - 거스름돈.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/09.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;

int main() {
    FASTIO
    cin >> n;
    vector<int> dp(n + 1, -1);
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    
    for (int i = 5; i <= n; i++) {
        if (dp[i - 2] != -1) {
            dp[i] = dp[i - 2] + 1;
        }
        if (dp[i - 5] != -1) {
            dp[i] = dp[i - 5] + 1;
        }
    }
    cout << dp[n];
    return 0;
}

/*
 편의점 카운터에서 일한다. 손님이 2원짜리와 5원짜리로만 거스름돈을 달라고 한다. 2원짜리 동전과 5원짜리 동전은 무한정 많이 가지고 있다.
 동전의 개수가 최소가 되도록 거슬러 주어야 한다. 거스름돈이 n인 경우, 최소 동전의 개수가 몇 개인지 알려주는 프로그램을 작성
 
 
 */
