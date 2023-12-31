//
//  10971 - 외판원 순회 2.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 11;

int N, startNode;
int ans = 1e9;

vector<vector<int>> W(MAX, vector<int> (MAX));
vector<bool> visited(MAX);

void DFS(int cur, int cost, int depth) {
    if (depth == N - 1) {
        if (W[cur][startNode]) {
            ans = min(ans, cost + W[cur][startNode]);
        }
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (!W[cur][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        DFS(i, cost + W[cur][i], depth + 1);
        visited[i] = false;
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        startNode = i;
        visited[i] = true;
        DFS(i, 0, 0);
        visited[i] = false;
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    solve();
    cout << ans;
    return 0;
}

/*
 외판원 순회 문제는 영어로 Traveling Salesman problem (TSP)라고 불리는 문제로 computer science 분야에서 가장 중요하게 취급되는 문제 중 하나이다.
 여러 가지 변종 문제가 있으나, 가장 일반적인 형태의 문제를 먼저 살펴보자.
 
 1번부터 N번까지 번호가 매겨져 있는 도시들이 있고, 도시들 사이에는 길이 있다. (길이 없을 수도 있다) 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행을 계획하려고 한다.
 단, 한 번 갔던 도시로는 다시 갈 수 없다. (맨 마지막에 여행을 출발했던 도시로 돌아오는 것은 예외)
 이런 여행 경로가 여러 가지가 있을 수 있는데, 가장 적은 비용을 들이는 여행 계획을 세우고자 한다.
 
 각각의 도시를 시작점으로 하여 모든 도시를 순회한 후 돌아올 수 있는지 확인하는 방식으로 완전탐색 풀이 진행
 시간복잡도 O(N^2)
 */
