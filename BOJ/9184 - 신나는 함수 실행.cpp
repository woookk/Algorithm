//
//  9184 - 신나는 함수 실행.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/26.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int a, b, c;
int dp[25][25][25];

int getValue(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return getValue(20, 20, 20);
    }
    if (dp[a][b][c] != 0) return dp[a][b][c];
    if (a < b && b < c) {
        dp[a][b][c] = getValue(a, b, c - 1) + getValue(a, b - 1, c - 1) - getValue(a, b - 1, c);
    }
    else {
        dp[a][b][c] = getValue(a - 1, b, c) + getValue(a - 1, b - 1, c) + getValue(a - 1, b, c - 1) - getValue(a - 1, b - 1, c - 1);
    }
    return dp[a][b][c];
}

int main() {
    FASTIO
    dp[0][0][0] = 1;
    while (true) {
        cin >> a >> b >> c;
        if (a == - 1 && b == -1 && c == -1) {
            break;
        }
        int result =  getValue(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
        
    }
    return 0;
}

/*
 재귀함수 w(a, b, c)
 if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
     1

 if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
     w(20, 20, 20)

 if a < b and b < c, then w(a, b, c) returns:
     w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

 otherwise it returns:
     w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
 
 위의 함수를 구현하는 것은 매우 쉽다. 하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다.
 a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.
 
 다이나믹 프로그래밍을 이용해서 풀이하려고 했으나 어떤 것부터 먼저 계산해야하는 순서가 애매하기 때문에 값을 저장하는 방식으로 메모이제이션 이용. 같은 값 두번 계산하지 않는 방식으로 풀이 진행
 같은 값 두 번 계산하지 않으면 시간 복잡도 최대 O(20^3)
 */
