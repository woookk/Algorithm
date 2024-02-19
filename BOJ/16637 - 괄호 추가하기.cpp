//
//  16637 - 괄호 추가하기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/19.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans = -1e9;
string formula;

int calculate(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    }
    if (op == '-') {
        return a - b;
    }
    return a * b;
}

void solve(int idx, int result) {
    if (idx >= N) {
        ans = max(ans, result);
        return;
    }
    
    char op = '+';
    if (idx != 0) op = formula[idx - 1];
    if (idx + 2 < N) {
        int bracket = calculate(formula[idx] - '0', formula[idx + 2] - '0', formula[idx + 1]);
        solve(idx + 4, calculate(result, bracket, op));
    }
    solve(idx + 2, calculate(result, formula[idx] - '0', op));
}

int main() {
    FASTIO
    cin >> N >> formula;
    solve(0, 0);
    cout << ans << "\n";
    return 0;
}

/*
 길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다. 연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다.
 수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다. (중첩된 괄호는 사용할 수 없다.)
 수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오.
 
 각 연산자마다 괄호 안에 넣을지 안 넣을지를 판단할 수 있다. 이 때 가능한 모든 경우의 수는 2^9이므로 완전 탐색으로 풀이 진행
 괄호 안에 넣을 경우,
    이전까지의 계산 값에 현재 값과 다음 값의 연산 결과를 연산해주면 되고
 괄호 안에 넣지 않을 경우,
    이전까지의 계산 값에 현재 값을 연산해주면 된다.
 */
