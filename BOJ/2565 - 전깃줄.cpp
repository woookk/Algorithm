//
//  2565 - 전깃줄.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, numberOfRemoves;

int main() {
    FASTIO
    cin >> N;
    vector<pair<int, int>> line(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        line[i] = { A, B };
    }
    sort(line.begin(), line.end());
    
    vector<int> dp(N, 0);
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (line[i].second > line[j].second) {
                count = max(count, dp[j]);
            }
        }
        dp[i] = count + 1;
        numberOfRemoves = max(numberOfRemoves, dp[i]);
    }
    cout << N - numberOfRemoves;
    return 0;
}

/*
 두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성
 
 전봇대 A를 기준으로 정렬한 후, 전봇대 B를 기준으로 가장 긴 증가하는 부분 수열을 구하게 되면 모든 전깃줄이 교차하지 않으면서 가장 많은 전깃줄을 선택하게 된다.
 */
