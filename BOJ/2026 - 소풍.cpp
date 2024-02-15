//
//  2026 - 소풍.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/15.
//

#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int K, N, F;

void solve(const vector<vector<bool>>& areFriends, vector<int>& taken, int cur) {
    if (taken.size() == K) {
        for (auto picked: taken) {
            cout << picked << "\n";
        }
        exit(0);
    }
    
    for (int next = cur + 1; next <= N; next++) {
        if (!areFriends[cur][next]) continue;
        bool isPossible = true;
        for (auto picked: taken) {
            if (!areFriends[picked][next]) {
                isPossible = false;
                break;
            }
        }
        
        if (!isPossible) continue;
        taken.push_back(next);
        solve(areFriends, taken, next);
        taken.pop_back();
    }
}

int main() {
    FASTIO
    cin >> K >> N >> F;
    vector<vector<bool>> areFriends(N + 1, vector<bool> (N + 1, false));
    for (int i = 0; i < F; i++) {
        int a, b;
        cin >> a >> b;
        areFriends[a][b] = true;
        areFriends[b][a] = true;
    }
    vector<int> taken;
    for (int st = 1; st <= N; st++) {
        taken.push_back(st);
        solve(areFriends, taken, st);
        taken.pop_back();
    }
    cout << -1 << "\n";
    return 0;
}

/*
 1부터 N까지 번호가 붙은 N명의 학생들 중에서 K명을 소풍을 보내려고 한다. 중간에 싸움이 일어나면 안되므로 소풍을 갈 학생들이 서로 친구 사이이기를 원한다.
 친구 관계에 대한 정보를 F개를 주시며 K명을 선발하라고 부탁하였다. 소풍을 가게될 K명을 결정하는 프로그램을 작성
 
 재귀를 이용한 완전 탐색으로 풀이 진행 + 백트래킹
 중복된 경우를 세지 않도록 학생들 중 가장 번호가 빠른 학생부터 그룹에 넣는 방식으로 진행하였고 기존 그룹과도 친구인지 확인하는 과정을 진행
 */
