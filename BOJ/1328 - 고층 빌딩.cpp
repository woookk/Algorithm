//
//  1328 - 고층 빌딩.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/25.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const int mod = 1e9 + 7;

int N, L, R;

int main() {
    FASTIO
    cin >> N >> L >> R;
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>> (N + 1, vector<ll> (N + 1, 0)));
    dp[1][1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
                dp[i][j][k] %= mod;
            }
        }
    }
    cout << dp[N][L][R];
    return 0;
}

/*
 빌딩 N개가 한 줄로 세워져있다. 모든 빌딩의 높이는 1보다 크고, N보다 작으며, 같은 높이를 가지는 빌딩은 없다.
 상근이는 학교 가는 길에 가장 왼쪽에 서서 빌딩을 몇 개 볼 수 있는지 보았고, 집에 돌아오는 길에는 가장 오른쪽에 서서 빌딩을 몇 개 볼 수 있는지 보았다.
 빌딩의 개수 N과 가장 왼쪽에서 봤을 때 보이는 빌딩의 수 L, 가장 오른쪽에서 봤을 때 보이는 빌딩의 수 R이 주어졌을 때, 가능한 빌딩 순서의 경우의 수를 구하는 프로그램을 작성
 
 다이나믹 프로그래밍을 이용한 방식으로 풀이
 건물의 개수가 N - 1일 때, 건물의 개수가 N개가 되기 위해서 N - 1개의 건물보다 높이가 작은 건물을 하나 세운다고 생각
 왼쪽에서 봤을 때 L - 1, 오른쪽에서 봤을 때 R인 경우: 가장 왼쪽에 높이가 가장 작은 건물을 세운다.
 왼쪽에서 봤을 때 L, 오른쪽에서 봤을때 R - 1인 경우: 가장 오른쪽에 높이가 가장 작은 건물을 세운다.
 왼쪽에서 봤을 때 L, 오른쪽에서 봤을 때 R: N - 1개 건물 사이 N - 2개 위치 중 하나에 높이가 가장 작은 건물을 세운다.
 점화식으로 정의하면 dp[N][L][R] = dp[N - 1][L - 1][R] + dp[N - 1][L][R - 1] + (N - 2) * dp[N - 1][R][L]
 */
