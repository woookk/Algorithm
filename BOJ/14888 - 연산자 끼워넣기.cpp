//
//  14888 - 연산자 끼워넣기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 12;
const int numberOfOperators = 4;

int N;
int minValue = INT_MAX, maxValue = INT_MIN;

vector<int> A(MAX);
vector<int> op(numberOfOperators);

void solve(int depth, int result) {
    if (depth == N - 1) {
        minValue = min(minValue, result);
        maxValue = max(maxValue, result);
        return;
    }
    
    for (int i = 0; i < numberOfOperators; i++) {
        if (op[i]) {
            op[i] -= 1;
            if (i == 0) {
                solve(depth + 1, result + A[depth + 1]);
            }
            else if (i == 1) {
                solve(depth + 1, result - A[depth + 1]);
            }
            else if (i == 2) {
                solve(depth + 1, result * A[depth + 1]);
            }
            else {
                solve(depth + 1, result / A[depth + 1]);
            }
            op[i] += 1;
        }
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < numberOfOperators; i++) {
        cin >> op[i];
    }
    solve(0, A[0]);
    cout << maxValue << "\n" << minValue;
    return 0;
}

/*
 N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 순서를 바꾸면 안된다.
 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다.
 
 N개의 수와 N - 1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
 
 연산자를 각각의 위치마다 다 넣어보면서 최댓값, 최솟값 갱신 (백트래킹)
 */
