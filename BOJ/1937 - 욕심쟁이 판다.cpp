//
//  1937 - 욕심쟁이 판다.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/09.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int n, ans;

int solve(vector<vector<int>>& board, vector<vector<int>>& dp, int curX, int curY) {
    
    int& cache = dp[curX][curY];
    if (cache != -1) return cache;
    
    cache = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (board[curX][curY] >= board[nx][ny]) continue;
        cache = max(cache, solve(board, dp, nx, ny) + 1);
    }
    return cache;
}

int main() {
    FASTIO
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, solve(board, dp, i, j));
        }
    }
    cout << ans;
    return 0;
}

/*
 n * n 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 그리고 그 곳의 대나무를 다 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동한다. 그리고 또 그곳에서 대나무를 먹는다.
 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다.
 판다가 이동할 수 있는 칸의 수의 최댓값을 구하는 프로그램을 작성
 
 각 칸에 대해서 DFS 또는 BFS를 돌리는 경우에는 N^2의 칸에 대해서 시간복잡도 O(N^2)이 소요되므로 시간초과가 발생한다.
 판다는 크기가 증가하는 순으로만 이동하므로 이전에 방문했던 칸에 대해서는 다시 방문할 수 없다.
 또한, 각 칸에서 이동할 수 있는 최대 칸 수를 저장해놓게 되면 저장해놓은 값을 이용해서 주위의 값도 구할 수 있다.
 다이나믹 프로그래밍을 이용하여 풀이를 진행
 */
