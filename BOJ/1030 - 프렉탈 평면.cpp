//
//  1030 - 프렉탈 평면.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/05.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int s, N, K, R1, R2, C1, C2;

int getColor(int len, int x, int y) {
    if (len == 1) {
        return 0;
    }
    int boundary = len / N;
    if (x >= boundary * (N - K) / 2 && x < boundary * (N + K) / 2
        && y >= boundary * (N - K) / 2 && y < boundary * (N + K) / 2) {
            return 1;
    }
    return getColor(boundary, x % boundary, y % boundary);
}

void printColor(int len) {
    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << getColor(len, i, j);
        }
        cout << "\n";
    }
}

int main() {
    FASTIO
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    if (s == 0) {
        cout << 0;
        return 0;
    }
    
    int len = 1;
    while (s--) {
        len *= N;
    }
    printColor(len);
    return 0;
}

/*
    프렉탈 평면은 시간 0에서 프렉탈은 흰색 정사각형 하나.
    단위 시간이 진행될 때마다 N * N개의 크기가 동일한 단위 정사각형으로 나누어진다.
    정사각형이 흰색이라면 가운데 K * K 정사각형이 검정색으로 채워진다.
 
    s, N, K, R1, R2, C1, C2가 주어질 때, 시간 s일 때, R1행 C1열부터 R2행 C2열까지 출력
    
    프렉탈 최대 크기 8^10 * 8^10 (s == 10, N == 8)
    배열에 전체를 그린 후 (R1, C1), (R2, C2)를 구하는 것이 아닌 다른 방식으로 접근해야한다.
    **주어진 (R1, C1) ~ (R2, C2)의 색만 알면되므로 각 점에 대해서 구하는 방식으로 접근**
 */
