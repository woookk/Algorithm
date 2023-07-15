//
//  28295 - 체육은 코딩과목 입니다.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/15.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

char dir[4] = {'N', 'E', 'S', 'W'};

int main() {
    FASTIO
    int curDirection = 0;
    for (int i = 0; i < 10; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            curDirection = (curDirection + 1) % 4;
        }
        else if (t == 2) {
            curDirection = (curDirection + 2) % 4;
        }
        else {
            curDirection = (curDirection + 3) % 4;
        }
    }
    cout << dir[curDirection];
    return 0;
}
