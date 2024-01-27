//
//  1014 - 컨닝.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC;
int N, M;

int countBits(int bit) {
    int result = 0;
    while (bit != 0) {
        result += (bit & 1);
        bit /= 2;
    }
    return result;
}

int solve(vector<int> &board, vector<vector<int>> &dp, int row, int prev) {
    if (row >= N) {
        return 0;
    }
    
    if (dp[row][prev] != -1) return dp[row][prev];
    
    dp[row][prev] = 0;
    for (int i = 0; i < (1 << M); i++) {
        if (i & board[row]) continue;
        bool isPossible = true;
        for (int j = 0; j < M; j++) {
            if (!(i & (1 << j))) continue;
            if (j > 0 && (i & (1 << (j - 1)))) {
                isPossible = false;
                break;
            }
            if (j < M - 1 && (i & (1 << (j + 1)))) {
                isPossible = false;
                break;
            }
            if (j > 0 && (prev & (1 << (j - 1)))) {
                isPossible = false;
                break;
            }
            if (j < M - 1 && (prev & (1 << (j + 1)))) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) dp[row][prev] = max(dp[row][prev], solve(board, dp, row + 1, i) + countBits(i));
    }
    return dp[row][prev];
}

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        cin >> N >> M;
        vector<int> board(N, 0);
        vector<vector<int>> dp(N, vector<int>(1 << 10, -1));
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == 'x') {
                    board[i] |= (1 << j);
                }
            }
        }
        cout << solve(board, dp, 0, 0) << "\n";
    }
    return 0;
}

/*
 몇몇 학생들이 시험을 보는 도중 다른 사람의 답지를 베끼려 한다.
 시험은 N행, M열 크기의 직사각형 교실에서 이루어진다. 교실은 1×1 크기의 단위 정사각형으로 이루어져 있는데, 각 단위 정사각형은 자리 하나를 의미한다.
 컨닝을 방지하기 위해서, 모든 학생은 자신의 왼쪽, 오른쪽 대각선 위, 왼쪽, 오른쪽, 이렇게 총 네 자리에 앉아있는 친구의 답지를 항상 베낀다고 가정하고 모든 학생이 컨닝을 할 수 없도록 배치되어야 한다.
 교실의 모양이 주어졌을 때, 이 곳에서 아무도 컨닝을 할 수 없도록 학생을 배치할 수 있는 최대 학생 수가 몇명인지 구하는 프로그램을 작성
 
 첫 번째 행은 왼쪽, 오른쪽 사람이 없다면 배치가 가능하다.
 두 번째 행부터는 바로 이전 행의 자리배치에만 영향을 받는다.
 
 이전 행의 자리배치를 비트마스킹을 이용하여 표현한 후,
 앉을 수 있는 모든 경우의 수에 대해서 자리 배치가 가능한지 확인하는 방식으로 풀이를 진행
 
 재귀와 다이나믹 프로그래밍 방식을 이용하여 풀이 진행
 */
