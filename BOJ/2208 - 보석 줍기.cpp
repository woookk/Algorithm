//
//  2208 - 보석 줍기.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MX = 1e5 + 5;
int N, M;
int value[MX], valueOfM[MX], dp[MX];

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> value[i];
        if (i <= M) {
            valueOfM[i] = valueOfM[i - 1] + value[i];
        }
        else {
            valueOfM[i] = valueOfM[i - 1] + value[i] - value[i - M];
        }
    }
    
    dp[M] = valueOfM[M];
    for (int i = M + 1; i <= N; i++) {
        dp[i] = max(dp[i - 1] + value[i], valueOfM[i]);
    }
    cout << *max_element(dp, dp + N + 1);
    return 0;
}

/*
    N개의 보석들이 일렬로 놓여 있었다.
    각각의 보석의 가치는 다를 수 있기 때문에, 가급적 많은 이득을 얻을 수 있도록 보석 가져간다.
    1. 1번 보석부터 N번 보석까지 순서대로 이동.
    2. 경보 장치 -> 보석을 주우면 M개 이상의 보석을 연속해서 주워야한다. 보석 줍기를 멈춘 후에는 다시 보석을 줍지 못한다.
    3. 주운 보석들의 가치의 총 합을 최대로
        
    dp[idx] -> idx를 마지막 원소로 하는 연속한 최댓값
    - idx까지 이전 M개
    - dp[idx - 1] + value[idx]
    위 두 값 중 큰 것이 dp[idx]
 */
