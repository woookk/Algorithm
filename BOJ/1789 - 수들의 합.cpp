//
//  1789 - 수들의 합.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/25.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
ll S, sum;
int N;

int main() {
    FASTIO
    cin >> S;
    
    for (int i = 1; ; i++) {
        sum += i;
        N++;
        if (sum > S) {
            N--;
            break;
        }
    }
    cout << N;
    return 0;
}

/*
 전체 합이 S보다 크게될 때까지 제일 작은 자연수부터 차례로 하나씩 더해준다.
 합이 S를 초과하게될때까지 더해준 횟수가 N의 최댓값
 */
