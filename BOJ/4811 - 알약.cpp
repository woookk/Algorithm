//
//  4811 - 알약.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/07.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int N;

ll solve(vector<vector<ll>>& dp, int whole, int half) {
    if (whole == 0) return 1;
    
    if (dp[whole][half] != -1) return dp[whole][half];
    
    dp[whole][half] = 0;
    if (whole > 0) {
        dp[whole][half] += solve(dp, whole - 1, half + 1);
    }
    if (half > 0) {
        dp[whole][half] += solve(dp, whole, half - 1);
    }
    return dp[whole][half];
}

int main() {
    FASTIO
    while (true) {
        cin >> N;
        if (N == 0) break;
        vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -1));
        cout << solve(dp, N, 0) << "\n";
    }
    return 0;
}

/*
 할아버지는 매일 매일 약 반알을 먹는다. 소녀는 약이 N개 담긴 병을 선물로 주었다.
 첫째 날에는 병에서 약 하나를 꺼낸다. 그 다음, 그 약을 반으로 쪼개서 한 조각은 먹고, 다른 조각은 다시 병에 넣는다.
 다음 날부터는 병에서 약을 하나 꺼낸다. 반 조각이라면 그 약을 먹고, 아니라면 반을 쪼개서 한 조각을 먹고, 다른 조각은 다시 병에 넣는다.
 할아버지는 손녀에게 한 조각을 꺼낸 날에는 W를, 반 조각을 꺼낸 날에는 H를 보낸다. 총 2N일이 지나면 길이가 2N인 문자열이 만들어지는데 이 때 가능한 서로 다른 문자열의 개수를 구하는 프로그램을 작성
 
 다이나믹 프로그래밍을 이용하여 풀이 진행
 한 조각 전체인 알약의 개수와 쪼개 진 알약의 개수를 이용해서 만들 수 있는 문자열의 개수를 저장해놓는 방식으로 풀이 진행
 */
