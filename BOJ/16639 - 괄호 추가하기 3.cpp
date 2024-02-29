//
//  16639 - 괄호 추가하기 3.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/29.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
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

int main() {
    FASTIO
    cin >> N >> formula;
    vector<vector<int>> minValue(N, vector<int>(N, INT_MAX)), maxValue(N, vector<int>(N, INT_MIN));
    for (int i = 0; i < N; i++) {
        if (!isdigit(formula[i])) continue;
        minValue[i][i] = formula[i] - '0';
        maxValue[i][i] = formula[i] - '0';
    }
    
    for (int i = 2; i < N; i += 2) {
        for (int j = 0; j < N - i; j += 2) {
            for (int k = 2; k <= i; k += 2) {
                vector<int> result(4);
                result[0] = calculate(minValue[j][j + k - 2], minValue[j + k][i + j], formula[j + k - 1]);
                result[1] = calculate(minValue[j][j + k - 2], maxValue[j + k][i + j], formula[j + k - 1]);
                result[2] = calculate(maxValue[j][j + k - 2], minValue[j + k][i + j], formula[j + k - 1]);
                result[3] = calculate(maxValue[j][j + k - 2], maxValue[j + k][i + j], formula[j + k - 1]);
                
                sort(result.begin(), result.end());
                
                minValue[j][j + i] = min(minValue[j][j + i], result[0]);
                maxValue[j][j + i] = max(maxValue[j][j + i], result[3]);
            }
        }
    }
    cout << maxValue[0][N - 1];
    return 0;
}

/*
 길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다. 곱하기의 연산자 연산자 우선순위가 더하기와 빼기보다 높기 때문에, 곱하기를 먼저 계산해야 한다. 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다.
 수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다.
 수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오.
 
 괄호 추가하기 2에서는 중첩된 괄호를 추가하지 못하였으므로 경우의 수가 한정되어 있어 완전 탐색으로 풀이 진행
 중첩된 괄호를 추가할 수 있을 경우 경우의 수가 매우 많아지므로 완전 탐색으로는 풀이할 수 없다.
 또한, 중첩된 괄호가 가능하기 때문에 연산자의 우선 순위가 중요하지 않다.
 
 행렬 곱셈 횟수를 구하는 방식과 유사하게
 다이나믹 프로그래밍을 이용하여 [i, j]의 최댓값을 구하는 방식으로 풀이를 진행
 */
