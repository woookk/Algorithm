//
//  10830 - 행렬 제곱.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
long long B;

void multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> result(N, vector<int> (N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += (a[i][k] * b[k][j]);
            }
            result[i][j] %= 1000;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = result[i][j];
        }
    }
}

int main() {
    FASTIO
    cin >> N >> B;
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> ans(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
        ans[i][i] = 1;
    }
    
    while (B) {
        if (B % 2) {
            multiply(ans, A);
        }
        multiply(A, A);
        B /= 2;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
    크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성 (A^B의 각 원소를 1,000으로 나눈 나머지를 출력)
 
    B의 최댓 값이 1000억까지이므로 하나씩 곱해주는 방식으로 풀이하면 시간 초과
    B가 홀수일 경우, 정답에 A를 한 번 곱해주고
    B가 짝수일 경우, A * A를 해서 A^2을 만들어준 후 B /= 2를 해주게 되면 A의 제곱값들로 답을 구할 수 있다.
    분할정복 어떻게 나누어 처리할지 잘 생각할 것.
 
    ** 1 ≤ B ≤ 100,000,000,000이므로 long long**
 */
