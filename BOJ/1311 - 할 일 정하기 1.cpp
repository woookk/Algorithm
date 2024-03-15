//
//  1311 - 할 일 정하기 1.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/09.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int solve(vector<vector<int>>& D,
           vector<vector<int>>& dp,
           int currentPerson,
           int visited) {
    if (visited == (1 << N) - 1) return 0;
    
    int &cache = dp[currentPerson][visited];
    if (cache != INT_MAX) return cache;
    
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) continue;
        cache = min(cache, solve(D, dp, currentPerson + 1, visited | (1 << i)) + D[currentPerson][i]);
    }
    return cache;
}

int main() {
    FASTIO
    cin >> N;
    vector<vector<int>> D(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }
    vector<vector<int>> dp(N, vector<int>(1 << N, INT_MAX));
    cout << solve(D, dp, 0, 0);
    return 0;
}

/*
 N명의 사람과 N개의 일이 있다. 각 사람은 일을 하나 담당해야 하고, 각 일을 담당하는 사람은 한 명이어야 한다.
 Dij를 i번 사람이 j번 일을 할 때 필요한 비용이라고 했을 때, 모든 일을 하는데 필요한 최솟값을 구하는 프로그램을 작성
 
 다이나믹 프로그래밍을 이용하여 풀이 진행
 현재 일을 할 사람과 완료된 일을 비트마스킹을 이용하여 넘겨주는 방식으로 풀이 진행
 
 */
