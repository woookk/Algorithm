//
//  2631 - 줄 세우기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main() {
    FASTIO
    cin >> N;
    vector<int> child(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> child[i];
    }

    vector<int> dp(N + 1, 1);
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (child[i] > child[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << N - *max_element(dp.begin(), dp.end());
    return 0;
}

/*
 N명의 아이들이 임의의 순서로 줄을 서 있을 때, 번호 순서대로 배치하기 위해 옮겨지는 아이의 최소 수를 구하는 프로그램을 작성
 
 가장 긴 증가하는 부분 수열을 제외하고는 순서대로 한 번씩 옮겨줘야 한다.
 가장 긴 증가하는 부분 수열(LIS)를 N^2 시간 복잡도로 구하는 방식으로 풀이 진행
 */
