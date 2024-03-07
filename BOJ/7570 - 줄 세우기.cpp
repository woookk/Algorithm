//
//  7570 - 줄 세우기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e6 + 5;

int N, maxLength;

int main() {
    FASTIO
    cin >> N;
    vector<int> child(N);
    for (int i = 0; i < N; i++) {
        cin >> child[i];
    }
    vector<int> dp(MAX, 0);
    for (int i = 0; i < N; i++) {
        dp[child[i]] = dp[child[i] - 1] + 1;
        maxLength = max(maxLength, dp[child[i]]);
    }
    cout << N - maxLength;
    return 0;
}

/*
 어린이집에 올해 입학한 어린이들이 놀이터에 한 줄로 서있다. 모든 어린이들에게는 입학할 때 주어진 번호가 있고 모두 옷에 번호표를 달고 있다. 그런데 어린이들은 아직 번호 순서대로 줄을 잘 서지 못하므로 선생님이 다음과 같은 방법을 사용해서 번호순서대로 줄을 세우려고 한다.
 줄 서 있는 어린이 중 한 명을 선택하여 제일 앞이나 뒤로 보낸다.
 처음에 줄 서 있는 상태에서 위 방법을 이용하여 번호 순서대로 줄을 세울 때 앞이나 뒤로 보내는 어린이의 수의 최솟값을 구하자.
 
 다이나믹 프로그래밍을 이용하여 풀이 진행
 어린이들의 번호로 증가하는 부분 수열을 구하면 해당 부분 수열에 포함되지 않는 어린이들은 앞이나 뒤로 보내지게 된다.
 **한 번에 작업으로는 맨 앞 or 맨 뒤로만 보낼 수 있으므로 증가하는 부분 수열이 아닌 1씩 증가하는 부분 수열을 구해야 한다.**
 */
