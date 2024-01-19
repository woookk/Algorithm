//
//  11049 - 행렬 곱셈 순서.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/16.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX;

int N;

int main() {
    FASTIO
    cin >> N;
    vector<vector<int>> matrix(N + 1, vector<int>(2));
    
    for (int i = 1; i <= N; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }
    
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = INF;
            for (int k = j; k < i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }
    }
    cout << dp[1][N];
    return 0;
}

/*
    크기가 N * M인 행렬 A와 M * K인 B를 곱할 때 필요한 곱셈 연산이 수는 총 N * M * K이다. 행렬 N개를 곱하는데 필요한 곱셈 연산의 수는 행렬을 곱하는 순서에 따라 달라지게 된다.
    행렬 N개의 크기가 주어졌을 때, 모든 행렬을 곱하는데 필요한 곱셈 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.
    
    A * B, B * C 두 행렬이 곱해진다면 A * C 행렬이 된다.
    행렬 N개(A * B, B * C, C * D, ..., Y * Z)가 곱해진다면 A * Z 행렬이 된다.
    결과물은 바뀌지 않지만 연산의 횟수만 행렬이 곱해지는 순서에 따라서 바뀌게 된다.
 
    구간에서 마지막으로 곱해지는 것을 하나씩 정한 후 모두 곱해보는 방식으로 연산의 최솟값을 구할 수 있고
    구간을 두 구간으로 나누어 1 ~ k, k + 1 ~ N 각각의 그룹에서의 연산 횟수의 최솟값을 구한 뒤 더하는 방법으로 접근
    이 때, 다이나믹 프로그래밍을 이용하여 각 구간의 최솟값을 저장
 */
