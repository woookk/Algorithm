//
//  1516 - 게임 개발.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 505;

int N;
int buildTime[MAX];

vector<int> adj[MAX];
int inDegree[MAX], totalTime[MAX];

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> buildTime[i];
        while (1) {
            int num;
            cin >> num;
            if (num == -1) break;
            adj[num].push_back(i);
            inDegree[i]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            totalTime[i] = buildTime[i];
        }
    }
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for (auto nx: adj[cur]) {
            inDegree[nx]--;
            if (inDegree[nx] == 0) {
                q.push(nx);
            }
            totalTime[nx] = max(totalTime[nx], buildTime[nx] + totalTime[cur]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << totalTime[i] << "\n";
    }
    return 0;
}

/*
 모든 건물을 짓는데 최소의 시간을 구해야한다. 어떤 건물을 짓기 위해서 다른 건물을 먼저 지어야 할 수도 있기 때문에 문제가 단순하지많은 않다.
 편의상 자원을 무한히 많이 가지고 있고, 건물을 짓는 명령을 내리기까지는 시간이 걸리지 않는다고 가정한다.
 
 건물별로 inDegree를 설정한 후 위상정렬을 이용하여 풀이 진행
 먼저 지어야하는 건물 + 현재 건물 짓는 시간과 totalTime을 비교하여 큰 값을 totalTime에 업데이트하는 방식으로 건물을 짓는데 걸리는 시간 구할 수 있다.
 */
