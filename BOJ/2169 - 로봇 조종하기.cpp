//
//  2169 - 로봇 조종하기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/06.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int dx[] = { 1, 0, 0 };
const int dy[] = { 0, 1, -1 };

int N, M;

ll solve(vector<vector<int>>& values, vector<vector<vector<ll>>>& dp, vector<vector<bool>>& visited, int curX, int curY, int direction) {
    if (curX == N - 1 && curY == M - 1) {
        return values[N - 1][M - 1];
    }
    
    ll &cache = dp[direction][curX][curY];
    if (cache != -1) return cache;
    
    cache = INT_MIN;
    visited[curX][curY] = true;
    
    for (int dir = 0; dir < 3; dir++) {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visited[nx][ny]) continue;
        cache = max(cache, solve(values, dp, visited, nx, ny, dir) + values[curX][curY]);
    }
    visited[curX][curY] = false;
    return cache;
}

int main() {
    FASTIO
    cin >> N >> M;
    vector<vector<int>> values(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> values[i][j];
        }
    }
    vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(N, vector<ll>(M, -1)));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    cout << solve(values, dp, visited, 0, 0, 0) << "\n";
    return 0;
}

/*
 화성 탐사를 위해 화성에 무선 조종 로봇을 보냈다. 로봇의 메모리가 얼마 안 되기 때문에 지형을 N * M 배열로 단순화하여 생각하자.
 지형의 고저차의 특성상, 로봇은 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로 이동할 수 있지만, 위쪽으로는 이동할 수 없다. 또한 한 번 탐사한 지역은 탐사하지 않기로 한다.
 각각의 지역은 탐사 가치가 있는데, 로봇을 배열의 왼쪽 위 (1, 1)에서 출발시켜 오른쪽 아래 (N, M)으로 보내려고 한다. 이때, 위의 조건을 만족하면서, 탐사한 지역들의 가치의 합이 최대가 되도록 하는 프로그램을 작성
 
 다이나믹 프로그래밍을 이용하여 풀이
 각각의 위치 별로 들어온 방향에 대해서 (N, M)까지의 최대 합을 저장하는 방식으로 풀이 진행
 */
