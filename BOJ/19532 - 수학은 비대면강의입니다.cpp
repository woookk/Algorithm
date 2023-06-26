//
//  19532 - 수학은 비대면강의입니다.cpp
//  cpp
//
//  Created by 민병욱 on 2023/06/26.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int a, b, c, d, e, f;

bool isPossible(int x, int y) {
    if (a * x + b * y == c && d * x + e * y == f) return true;
    return false;
}

int main() {
    FASTIO
    cin >> a >> b >> c >> d >> e >> f;
    
    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            if (isPossible(x, y)) {
                cout << x << " " << y << "\n";
                return 0;
            }
        }
    }
    return 0;
}

/*
 문자가 2개인 연립방정식을 해결하는 방법에 대해 강의, 다음과 같은 문제를 숙제
 다음 연립방정식에서 x와 y의 값을 계산하시오.
    ax + by = c
    dx + ey = f
 
 -999 ~ 999까지 정수만 입력 가능
 문제에서 언급한 방정식을 만족하는 (x,y)가 유일하게 존재하고, 이 때 x와 y가 각각
 -999 이상 999 이하의 정수인 경우만 입력으로 주어짐이 보장된다.
 */
