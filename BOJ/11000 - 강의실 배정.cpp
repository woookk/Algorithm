//
//  11000 - 강의실 배정.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;

int main() {
    FASTIO
    cin >> N;
    vector<pair<int, int>> classes(N);
    for (int i = 0; i < N; i++) {
        cin >> classes[i].first >> classes[i].second;
    }
    sort(classes.begin(), classes.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(classes[0].second);
    
    for (int i = 1; i < N; i++) {
        pq.push(classes[i].second);
        while (pq.top() <= classes[i].first) {
            pq.pop();
        }
        ans = max(ans, (int) pq.size());
    }
    cout << ans;
    return 0;
}

/*
 선생님에게 새로운 과제가 주어졌다. 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
 참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti <= Sj일 경우 i 수업과 j 수업을 같이 들을 수 있다.)
 최소의 강의실을 사용해서 모든 수업을 가능하게 하는 강의실의 개수를 출력하는 프로그램을 작성
 
 완전 탐색을 이용한 풀이는 O(N^2) 시간복잡도가 걸리므로 시간초과 발생
 
 우선순위 큐를 이용한 방식으로 풀이 진행
 끝나는 시간을 우선 순위 큐에 넣어 놓은 후 시작 시간이 증가하는 순으로 탐색
 시작 시간이 끝나는 시간보다 지났다면 제거해주는 방식으로 풀이
 제거된 후 우선 순위 큐의 최댓값이 필요한 최소의 강의실 수
 */
