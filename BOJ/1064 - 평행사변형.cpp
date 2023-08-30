//
//  1064 - 평행사변형.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/30.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

typedef struct {
    int x, y;
}Point;

bool isLine(Point a, Point b, Point c) {
    if (a.x == b.x && b.x == c.x) {
        return true;
    }
    else if (a.x == b.x || b.x == c.x || a.x == c.x) {
        return false;
    }
    else {
        if ((double)(c.y - b.y) / (c.x - b.x) == (double)(b.y - a.y) / (b.x - a.x)) {
            return true;
        }
        return false;
    }
}

int main() {
    FASTIO
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    
    if (isLine(a, b, c)) {
        cout << "-1.0" << "\n";
        return 0;
    }
    double ab, bc, ac;
    ab = sqrt(pow(b.y - a.y, 2) + pow(b.x - a.x, 2));
    bc = sqrt(pow(c.y - b.y, 2) + pow(c.x - b.x, 2));
    ac = sqrt(pow(c.y - a.y, 2) + pow(c.x - a.x, 2));
    
    double maxValue = max(max(ab + bc, bc + ac), ab + ac) * 2;
    double minValue = min(min(ab + bc, bc + ac), ab + ac) * 2;
    
    cout << fixed;
    cout.precision(12);
    
    cout << maxValue - minValue << "\n";
    return 0;
}

/*
 평행 사변형은 평행한 두 변을 가진 사각형이다. (두 쌍의 변이 각각 평행한 사각형)
 세 개의 서로 다른 점(A, B, C)이 주어질 때, 적절히 점 D를 찾아서 네 점으로 평행사변형을 만들고 이 때 만들어진 모든 사각형 중 가장 큰 둘레의 길이와 가장 작은 둘레의 길이의 차이를 구하시오.
 만들 수 있는 평행사변형이 없다면 -1을 출력한다.
 
 1. 만들 수 있는 평행 사변형이 없을 경우 -> 세 점이 한 직선에 있을 경우
 
 2. AB, BC / AB, AC / AC, BC의 경우 모두 따져서 각각 둘레의 길이를 구할 수 있다. 둘레의 길이 비교 후 최솟값, 최댓값 출력
 
 두 점 기울기 비교할 때 int형 자료구조인것 주의해서 풀이 (double로 치환해주지 않을 경우 비교 불가)
 */
