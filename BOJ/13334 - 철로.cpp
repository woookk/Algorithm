//
//  13334 - 철로.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, d;
int ans;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    FASTIO
    cin >> n;
    vector<pair<int, int>> path;
    for (int i = 0; i < n; i++) {
        int st, end;
        cin >> st >> end;
        if (st > end) {
            swap(st, end);
        }
        path.push_back({ st, end });
    }
    cin >> d;
    
    sort(path.begin(), path.end(), cmp);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [st, end]: path) {
        if (end - st > d) continue;
        pq.push(st);
        
        while (!pq.empty()) {
            if (pq.top() < end - d) {
                pq.pop();
                continue;
            }
            ans = max(ans, (int) pq.size());
            break;
        }
    }
    cout << ans;
    return 0;
}

/*
 집과 사무실을 통근하는 n명의 사람들이 있다. 각 사람의 집과 사무실은 수평선 상에 서로 다른 점에 위치하고 있다. 임의의 두 사람 A, B에 대하여, A의 집 혹은 사무실의 위치가 B의 집 혹은 사무실의 위치와 같을 수 있다.
 통근을 하는 사람들의 편의를 위하여 일직선 상의 어떤 두 점을 잇는 철로를 건설하여, 기차를 운행하려고 한다. 제한된 예산 때문에, 철로의 길이는 d로 정해져 있다.
 집과 사무실의 위치 모두 철로 선분에 포함되는 사람의 수가 최대가 되도록, 철로 선분을 정하고자 한다.
 길이 d의 모든 선분 L에 대하여, 집과 사무실의 위치가 모두 L에 포함되는 사람들의 최대 수를 구하는 프로그램을 작성
 
 도착 위치를 기준으로 오름차순 정렬
 출발 위치까지의 거리가 d보다 작다면 우선 순위 큐에 넣어준 후
 우선 순위 큐에서 출발 위치가 d보다 멀어진 경로들을 제거하고 최대 사용자수를 갱신하는 방식으로 풀이 진행
 
 정렬 시간복잡도 O(NlogN), n개의 경로에 대해서 최대 n번 삽입, n번 제거 시간복잡도 O(NlogN)
 시간 복잡도 O(NlogN)
 */
