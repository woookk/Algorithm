//
//  1946 - 신입 사원.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e6 + 5;

int TC;

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;
        vector<pair<int, int>> rank;
        for (int i = 0; i < N; i++) {
            int document, interview;
            cin >> document >> interview;
            rank.push_back({document, interview});
        }
        sort(rank.begin(), rank.end());
        
        int ans = 0;
        int minimumScore = MAX;
        
        for (int i = 0; i < N; i++) {
            auto [document, interview] = rank[i];
            if (interview < minimumScore) {
                ans++;
                minimumScore = interview;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
 신규 사원 채용을 실시한다. 인재 선발 시험은 1차 서류심사와 2차 면접시험으로 이루어진다.
 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다.
 즉, 어떤 지원자 A의 성적이 다른 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.
 이러한 조건을 만족시키면서, 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 구하는 프로그램을 작성하시오.
 
 서류 성적이 높은 순으로 정렬한 후 최소 인터뷰 등수보다 성적이 높다면 채용하는 방식으로 풀이 진행
 */
