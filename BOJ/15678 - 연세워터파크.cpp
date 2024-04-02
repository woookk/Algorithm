//
//  15678 - 연세워터파크.cpp
//  cpp
//
//  Created by 민병욱 on 2024/04/02.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N, D;
ll ans = LONG_LONG_MIN;

int main() {
    FASTIO
    cin >> N >> D;
    vector<ll> bridges(N);
    for (int i = 0; i < N; i++) {
        cin >> bridges[i];
        
    }
    
    priority_queue<pair<ll, int>> pq;
    pq.push({ bridges[0], 0 });
    for (int i = 1; i < N; i++) {
        while (true) {
            if (i - pq.top().second > D) pq.pop();
            else break;
        }
        auto prev = pq.top();
        pq.push({ max(prev.first + bridges[i], bridges[i]), i });
        ans = max(ans, pq.top().first);
    }
    cout << ans;
    return 0;
}

/*
 매년 여름 깜짝 워터파크를 개장한다. 워터파크가 발생할 장소는 알 수 없지만, 보통 도서관이나 서문 쪽에 개장한다는 사실만이 알려져 있다.
 학교에서는 학생들이 워터파크를 더 즐길 수 있도록 정수 Ki가 쓰여진 징검다리 N개를 놓아 두었다. 이 징검다리를 이용해 여러 명이 즐길 수 있는 재미 있는 게임을 하나 생각해냈다.
 - 각 사람은 시작점으로 쓸 징검다리 하나를 아무 것이나 하나 고른다.
 - 시작점에서 출발한 뒤 계속 점프하여 징검다리를 몇 개든 마음대로 밟은 뒤, 나오고 싶을 때 나온다. (시작점에서 바로 나오는 것도 가능하다.)
 - 시작점을 포함해, 밟은 모든 징검다리에 쓰여진 정수의 합이 가장 큰 사람이 이긴다.
 - N개의 모든 징검다리에 순서대로 1 ~ N의 번호를 붙인다. U번 징검다리에서 V번 징검다리로 점프하기 위해서는, U와 V의 차이가 미리 정해진 값 D 이하여야 한다.
 - 어떤 징검다리도 두 번 이상 밟을 수 없다.
 게임에서 최대 몇 점을 얻을 수 있는지 구하는 프로그램을 작성
 
 다이나믹 프로그래밍을 이용하여 접근
 뛰어 다니는 방향이 정해져 있지 않으므로 왼쪽에서 오른쪽으로 순서대로 밟는다고 생각한다.
 
 각각의 지점을 마지막으로 밟아서 얻을 수 있는 최대 점수를 구하는 방식으로 풀이가 가능하다.
 각각의 위치에서 왼쪽 D개를 살펴보며 최댓값을 갱신해주는 방식으로 풀이를 할 수 있지만, 시간복잡도가 O(N^2)이므로 시간초과가 발생할 수 있다.
 우선순위 큐를 이용하여 왼쪽 D개를 살펴보는 시간복잡도를 줄일 수 있다. 시간복잡도가 O(NlogN)이 되므로 해결 가능하다.
 
 */
