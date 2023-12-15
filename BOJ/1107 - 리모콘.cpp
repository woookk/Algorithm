//
//  1107 - 리모콘.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, ans;

bool canMove(vector<bool> btn, int channel) {
    if (channel == 0) {
        if (!btn[0]) {
            return false;
        }
        return true;
    }
    
    while (channel > 0) {
        if (!btn[channel % 10]) {
            return false;
        }
        channel /= 10;
    }
    return true;
}

int main() {
    FASTIO
    cin >> N >> M;
    vector<bool> btn(10, true);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        btn[num] = false;
    }
    
    ans = abs(N - 100);
    
    for (int channel = 0; channel <= 1000000; channel++) {
        if (!canMove(btn, channel)) continue;
        int len = (int) to_string(channel).length();
        int count = len + abs(N - channel);
        ans = min(ans, count);
    }
    cout << ans;
}

/*
 리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고 있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다.
 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대만큼 있다.
 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성
 
 채널이 최대 50만까지 존재하므로 100만까지의 채널이 각각 이동가능한지 확인한 후 버튼 누른 횟수 업데이트하는 방식으로 풀이
 */
