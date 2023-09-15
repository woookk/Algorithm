//
//  14567 - 선수과목 (Prerequisite).cpp
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

const int MAX = 1005;

int N, M;
vector<int> adj[MAX];
int inDegree[MAX];
int ans[MAX];

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        inDegree[B]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) q.push(i);
        ans[i] = 1;
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nx: adj[cur]) {
            inDegree[nx]--;
            if(inDegree[nx] == 0) {
                q.push(nx);
                ans[nx] = max(ans[nx], ans[cur] + 1);
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

/*
 학부에 개설된 모든 전공과목을듣고 졸업하려는 원대한 목표를 세웠다. 어떤 과목들은 선수과목이 있어 해당되는 모든 과목을 먼저 이수해야만 해당 과목을 이수할 수 있게 되어 있다.
 선수과목 조건을 지킬 경우 각각의 전공과목을 언제 이수할 수 있는지 궁금해졌다. 계산을 편리하게 위해 아래와 같이 조건을 간소화하여 계산
 1. 한 학기에 들을 수 있는 과목 수에는 제한이 없다.
 2. 모든 과목은 매 학기 항상 개설
 모든 과목에 대해 각 과목을 이수하려면 최소 몇 학기가 걸리는지 계산하는 프로그램 작성
 
 과목별 inDegree를 설정한 후 위상정렬을 이용하여 풀이 진행
 */
