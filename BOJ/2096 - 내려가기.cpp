//
//  2096 - 내려가기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main() {
    FASTIO
    cin >> N;
    vector<int> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }
    
    vector<int> prevMax(3, 0), prevMin(3, 0), curMax(3, 0), curMin(3, 0);
    for (int i = 0; i < 3; i++) {
        curMax[i] = prevMax[i] = board[i];
        curMin[i] = prevMin[i] = board[i];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[j];
        }
        curMax[0] = max(prevMax[0], prevMax[1]) + board[0];
        curMax[1] = max(max(prevMax[0], prevMax[1]), prevMax[2]) + board[1];
        curMax[2] = max(prevMax[1], prevMax[2]) + board[2];
        curMin[0] = min(prevMin[0], prevMin[1]) + board[0];
        curMin[1] = min(min(prevMin[0], prevMin[1]), prevMin[2]) + board[1];
        curMin[2] = min(prevMin[1], prevMin[2]) + board[2];
        
        for (int j = 0; j < 3; j++) {
            prevMax[j] = curMax[j];
            prevMin[j] = curMin[j];
        }
    }
    cout << max(max(curMax[0], curMax[1]), curMax[2]) << " " << min(min(curMin[0], curMin[1]), curMin[2]);
}



/*
 N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀있다. 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이
 먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다. 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다.
 숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오. 점수는 위치한 곳의 수의 합이다.
 
 단순하게 3차원 배열을 선언하여 각각의 위치에서 최소 점수와 최대 점수를 다이나믹 프로그래밍을 이용하여 풀이하였을 때,
 (메모리 제한 4MB) N개의 원소를 가지도록 배열을 선언하면 100000 * 4Byte 4MB이므로 메모리 초과 발생
 
 배열을 최소한으로만 선언해서 메모리를 줄인 방식으로 풀이 진행
 */
