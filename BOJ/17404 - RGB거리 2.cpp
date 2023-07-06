//
//  17404 - RGB거리 2.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/06.
//

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 2;

int N;
int RGB[3][1005];
int dp[3][1005];
int ans = INF;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> RGB[0][i] >> RGB[1][i] >> RGB[2][i];
    }
    
    for (int color = 0; color < 3; color++) {
        for (int i = 0; i <= 2; i++) {
            if (color == i) {
                dp[i][1] = RGB[i][1];
            }
            else {
                dp[i][1] = INF;
            }
        }
        
        for (int i = 2; i <= N; i++) {
            dp[0][i] = RGB[0][i] + min(dp[1][i - 1], dp[2][i - 1]);
            dp[1][i] = RGB[1][i] + min(dp[0][i - 1], dp[2][i - 1]);
            dp[2][i] = RGB[2][i] + min(dp[0][i - 1], dp[1][i - 1]);
        }
        
        for (int i = 0; i <= 2; i++) {
            if (i == color) continue;
            else ans = min(ans, dp[i][N]);
        }
    }
    cout << ans;
    return 0;
}


/*
    RGB거리에는 집이 N개 존재. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
    집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야한다.
    각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값 구해보자
    - 1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
    - N번 집의 색은 N - 1번, 1번 집의 색과 같지 않아야 한다.
    - i번 집의 색은 i - 1, i + 1번 집의 색과 같지 않아야 한다.
    
    i번째 집의 색은 i - 1번째 집의 색깔에만 영향을 받기 때문에 다이나믹 프로그래밍을 이용하여 구할 수 있다.
    1번 집이 R, G, B일 때 각각 다이나믹 프로그래밍을 이용하여 N - 1번 집까지 칠하는 비용을 구할 수 있고 N번째집은 N - 1, 1번째 집의 색깔에 영향을 받으므로 예외처리를 해준다.
 */
