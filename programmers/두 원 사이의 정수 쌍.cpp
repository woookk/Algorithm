//
//  두 원 사이의 정수 쌍.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/30.
//

#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll solution(int r1, int r2) {
    ll answer = 0;
    for (ll x = 1; x <= r2; x++) {
        
        ll y1 = 0, y2 = floor(sqrt(pow(r2, 2) - pow(x, 2)));
        if (x <= r1) {
            y1 = ceil(sqrt(pow(r1, 2) - pow(x, 2)));
        }
        answer += (y2 - y1) + 1;
    }
    answer *= 4;
    return answer;
}

/*
x축과 y축으로 이루어진 2차원 직교 좌표계에 중심이 원점인 서로 다른 크기의 원이 두개 주어진다.
반지름을 나타내는 두 정수 r1, r2가 매개변수로 주어질 때 두 원 사이 공간에 x좌표와 y좌표가 모두 정수인 점의 개수

x좌표에 따른 두 원의 y좌표를 구한 후 반지름이 y좌표 비교를 통하여 x좌표에 따른 점의 개수를 구할 수 있다.
x >= 1인 1사분면만 계산한 후 4를 곱해주게 되면 전체 원 안에 있는 모든 점을 구할 수 있게된다.

pow 함수를 사용하지 않게 되면 자료형의 변경으로 인하여 오버플로우 발생으로 오답처리
*/
