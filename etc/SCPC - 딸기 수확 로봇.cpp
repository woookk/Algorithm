//
//  SCPC - 딸기 수확 로봇.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/28.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int Answer;

int main() {
    FASTIO
    int T, test_case;
    
    cin >> T;
    for (test_case = 1; test_case <= T; test_case++) {
        Answer = 0;
        int N, D;
        cin >> N >> D;
        
        map<int, int> coords;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                Answer++;
                continue;
            }
            if (coords.find(x) != coords.end()) {
                coords[x]++;
                continue;
            }
            coords.insert({x, 1});
        }
        
        vector<pair<int, int>> negative;
        vector<pair<int, int>> positive;
        positive.push_back({0, 0});
        negative.push_back({0, 0});
        for (auto it: coords) {
            if (it.first < 0) {
                negative.push_back({abs(it.first), it.second});
            }
            else {
                positive.push_back({it.first, it.second});
            }
        }
        
        sort(negative.begin(), negative.end());
        
        for (int i = 1; i < negative.size(); i++) {
            negative[i].second += negative[i - 1].second;
        }
        
        for (int i = 1; i < positive.size(); i++) {
            positive[i].second += positive[i - 1].second;
        }
        
        if (negative.size() == 1) {
            for (auto it: positive) {
                if (it.first <= D) {
                    Answer = max(Answer, it.second);
                }
            }
        }
        else if (positive.size() == 1) {
            for (auto it: negative) {
                if (it.first <= D) {
                    Answer = max(Answer, it.second);
                }
            }
        }
        else {
            int positiveIdx = 0, negativeIdx = (int)negative.size() - 1;
            while (negativeIdx > 0 && positiveIdx < positive.size()) {
                int mn = min(negative[negativeIdx].first, positive[positiveIdx].first);
                int mx = max(negative[negativeIdx].first, positive[positiveIdx].first);
                if (mn * 2 + mx <= D) {
                    Answer = max(Answer, negative[negativeIdx].second + positive[positiveIdx].second);
                    positiveIdx++;
                }
                else {
                    negativeIdx--;
                }
            }
            positiveIdx = (int)positive.size() - 1;
            negativeIdx = 0;
            while (positiveIdx > 0 && negativeIdx < negative.size()) {
                int mn = min(negative[negativeIdx].first, positive[positiveIdx].first);
                int mx = max(negative[negativeIdx].first, positive[positiveIdx].first);
                if (mn * 2 + mx <= D) {
                    Answer = max(Answer, negative[negativeIdx].second + positive[positiveIdx].second);
                    negativeIdx++;
                }
                else {
                    positiveIdx--;
                }
            }
        }
        cout << "Case #" << test_case << "\n";
        cout << Answer << "\n";
    }
    
    return 0;
}

/*
 밭에 기른 딸기 수확하려고 한다. 로봇을 한 번 써서 가장 많은 수의 딸기를 수확하고 싶다.
 
 편의상 밭은 1차원, 즉 X축이라고 하자. 밭에는 N개의 딸기들이 있고 각 딸기들의 좌표가 주어진다. 딸기들의 좌표는 양수, 음수, 0이 모두 가능하다.
 여러 딸기의 좌표가 같을 수 있다.
 
 로봇의 시작 위치는 원점 즉 X좌표가 0인 점이다. 로봇의 마지막 위치는 어디든 상관이 없다. 단, 로봇이 최대 이동할 수 있는 최대 거리는 D이다.
 
 로봇이 이동할 수 있는 거리와 딸기들의 좌표를 입력으로 받아 수확할 수 있는 최대의 딸기 개수를 계산하는 프로그램을 작성하라.
 
 */
