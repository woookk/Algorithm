//
//  1700 - 멀티탭 스케줄링.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/13.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
    
int N, K, ans;
int tap[105];
int schedule[105];

int main() {
    FASTIO
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }
    
    for (int i = 0; i < K; i++) {
        bool isUsed = false;
        for (int j = 0; j < N; j++) {
            if (schedule[i] == tap[j]) {
                isUsed = true;
                break;
            }
        }
        if (isUsed) continue;
        
        for (int j = 0; j < N; j++) {
            if (tap[j] == 0) {
                tap[j] = schedule[i];
                isUsed = true;
                break;
            }
        }
        if (isUsed) continue;
        
        int removedIdx = -1;
        int lastScheduleIdx = -1;
        for (int j = 0; j < N; j++) {
            int remainingTurn = 0;
            for (int k = i + 1; k < K; k++) {
                if (tap[j] == schedule[k]) break;
                remainingTurn++;
            }
            if (remainingTurn > lastScheduleIdx) {
                removedIdx = j;
                lastScheduleIdx = remainingTurn;
            }
        }
        tap[removedIdx] = schedule[i];
        ans++;
    }
    cout << ans;
    return 0;
}

/*
    플러그 빼는 횟수 최소화하는 문제
    멀티탭 구멍의 개수 N, 전기용품의 촛 사용 횟수 K
    전기용품 이름이 K이하 자연수로 순서대로 주어진다.
 */
