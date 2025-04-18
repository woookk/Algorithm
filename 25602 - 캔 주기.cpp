//
//  25602 - 캔 주기.cpp
//  cpp
//
//  Created by 병욱 민 on 4/18/25.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int ans;

const int MAX = 5;

vector<int> A(MAX + 1);
vector<vector<int>> R(MAX * 2, vector<int>(MAX));

void solve(int sum, int depth) {
    if (depth == 2 * K) {
        ans = max(ans, sum);
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (A[i] <= 0) continue;
        A[i]--;
        solve(sum + R[depth][i], depth + 1);
        A[i]++;
    }
}

int main() {
    FASTIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < 2 * K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> R[i][j];
        }
    }
    solve(0, 0);
    cout << ans;
    return 0;
}

/*
 고양이 둘에게 매일 아침 캔을 정확히 하나씩 준다.
 캔의 종류는 N가지로, 집사는 i번째 캔을 A[i]개 갖고 있다.
 
 고양이들은 입맛이 까다롭고 변덕이 심해서 매일 각 캔에 대한 만족도가 다르다. 집사가 현재 가진 캔으로 고양이들에게 하루에 하나의 캔을 줘서 얻을 수 있는 만족도의 합의 최댓값을 구하는 프로그램을 작성하자.
 
 브루트포스 & 백트래킹 이용해서 문제풀이 진행한다. N, K 모두 10 이하이므로 시간초과 발생하지 않는다.
 */
