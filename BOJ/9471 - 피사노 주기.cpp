//
//  9471 - 피사노 주기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/13.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 5 * 1e5;

int TC;

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        int N, M;
        cin >> N >> M;
        vector<int> fibonacci(MAX + 1, 0);
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        int k;
        for (int i = 2; ; i++) {
            fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % M;
            if (fibonacci[i - 1] == 0 && fibonacci[i] == 1) {
                k = i - 1;
                break;
            }
        }
        cout << N << " " << k << "\n";
    }
    return 0;
}

/*
 1960년, IBM의 직원 Donald Wall은 피보나치 수열을 m으로 나눈 나머지가 주기를 이룬다는 것을 증명했다.
 나머지를 이용해서 만든 수열은 주기가 나타날 수 있다. k(m)을 반복하는 부분 수열의 길이라고 했을 때, k(11) = 10임을 알 수 있다.

 Wall은 아래와 같은 여러 가지 성질도 증명했다.
 m > 2인 경우에 k(m)은 짝수이다.
 임의의 짝수 정수 n > 2에 대해서, k(m) = n인 m이 항상 존재한다.
 k(m) ≤ m^2 - 1
 k(2^n) = 3 * 2(n-1)
 k(5^n) = 4 * 5^n
 k(2 * 5n) = 6n
 n > 2라면, k(10^n) = 15 * 10(n-1)
 m이 주어졌을 때, k(m)을 구하는 프로그램을 작성
 
 브루트포스 알고리즘을 이용하여 문제 풀이 진행
 fibonacci[i - 1] == 0 && fibonacci[i] == 1이 될 때 k(m)은 i - 1이 된다.
 */
