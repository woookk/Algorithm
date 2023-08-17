//
//  14939 - 불 끄기.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/13.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 10;
const int INF = INT_MAX;

int initialBulb[MAX];
int currentSimulation[MAX];

/**
 XOR 이용하여 전구 누르는 함수
 자기 자신, 위, 아래, 왼쪽, 오른쪽 다 확인
 위, 아래, 왼쪽, 오른쪽이 있을 시 전구 눌러줌
 */
void pressBulb(int row, int col) {
    currentSimulation[row] ^= (1 << (MAX - col - 1));
    if (row) {
        currentSimulation[row - 1] ^= (1 << (MAX - col - 1));
    }
    if (row != MAX - 1) {
        currentSimulation[row + 1] ^= (1 << (MAX - col - 1));
    }
    if (col) {
        currentSimulation[row] ^= (1 << (MAX - col));
    }
    if (col != MAX - 1) {
        currentSimulation[row] ^= (1 << (MAX  - col - 2));
    }
}

 

int main() {
    FASTIO
    for (int row = 0; row < MAX; row++) {
        for (int col = MAX - 1; col >= 0; col--) {
            char c;
            cin >> c;
            if (c == 'O') {
                initialBulb[row] |= (1 << col);
            }
        }
    }
    
    int result = INF;
    
    for (int candidate = 0; candidate < (1 << MAX); candidate++) {
        int press = 0;
        for (int row = 0; row < MAX; row++) {
            currentSimulation[row] = initialBulb[row];
        }
        
        for (int col = 0; col < MAX; col++) {
            if (candidate & (1 << col)) {
                pressBulb(0, col);
                press++;
            }
        }
        
        for (int row = 1; row < MAX; row++) {
            for (int col = 0; col < MAX; col++) {
                if ((currentSimulation[row - 1] & (1 << (MAX - col - 1))) != 0) {
                    pressBulb(row, col);
                    press++;
                }
            }
        }
        
        if (currentSimulation[MAX - 1] == 0)
        result = min(result, press);
    }
    if (result == INF) {
        cout << -1 << "\n";
    }
    else {
        cout << result << "\n";
    }
    return 0;
}

/*
 전구 100개가 10×10 정사각형 모양으로 늘어서 있다. 전구에 달린 스위치를 누르면 그 전구와 위, 아래, 왼쪽, 오른쪽에 있는 전구의 상태도 바뀐다. 전구 100개의 상태가 주어지면 모든 전구를 끄기 위해 최소한으로 눌러야 하는 스위치의 개수를 출력
 
 누른 칸은 다시 누를 필요가 없다. (한 번 누른칸 다시 누르게 되면 원상 복구)
 순서 상관 X
 
 모든 경우를 다 눌러보는 풀이는 전구가 총 100개이므로 각각의 전구에 대해서 눌러야할지를 판단해야하므로 2^100의 시간 복잡도. 시간 초과가 발생한다.
 
 맨 왼쪽 윗줄부터 차례대로 진행한다고 생각.
 모든 전구를 끄기 위해서는 두 번째 줄부터는 위쪽이 켜져있으면 꺼줘야한다.
 전체를 완전 탐색으로 돌리는 것이 아닌 첫 줄만 완전 탐색으로 진행하게 되면 나머지는 윗 줄에 따라서 결정된다. (2^10 경우의 수)
 */
