//
//  11444 - 피보나치 수 6.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/13.
//

#include <iostream>
#include <map>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const int MOD = 1e9 + 7;

ll n;

map<ll, ll> fibonacci;

ll solve(ll num) {
    if (fibonacci[num]) return fibonacci[num];
    
    if (num % 2 == 0) {
        fibonacci[num] = (solve(num / 2) * (solve(num / 2 + 1) + solve(num / 2 - 1))) % MOD;
        return fibonacci[num];
    }
    fibonacci[num] = ((solve((num + 1) / 2) * solve((num + 1) / 2)) % MOD + (solve((num - 1) / 2) * solve((num - 1) / 2)) % MOD) % MOD;
    return fibonacci[num];
}

int main() {
    FASTIO
    cin >> n;
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    fibonacci[2] = 1;
    cout << solve(n);
    return 0;
}

/*
 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
 이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n >= 2)가 된다.
 n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성 (n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력)
 
 
 **피사노 주기를 활용해서 문제를 풀이할 수 있다. 피사노 주기의 성질에서 m = 10^n (n > 2)일 때 피사노 주기 K(m) = 15 * 10^(n - 1)이다.**
 피사노 주기를 활용하려하였지만 피사노 주기를 구하는 과정에서 시간 초과가 발생할 여지가 있으므로 다른 문제풀이 적용
 
 fibonacci[n] = fibonacci[n - 1] + fibonacci[n - 2];
 fibonacci[n] = 2 * fibonacci[n - 2] + fibonacci[n - 3];
 fibonacci[n] = 3 * fibonacci[n - 3] + 2 * fibonacci[n - 4];
 fibonacci[n] = 5 * fibonacci[n - 4] + 3 * fibonacci[n - 5]; (fibonacci[2] = 1, fibonacci[3] = 2, fibonacci[4] = 3, fibonacci[5] = 5)
 fibonacci[n] = fibonacci[5] * fibonacci[n - 4] + fibonacci[4] * fibonacci[n - 5];
 fibonacci[n] = fibonacci[6] * fibonacci[n - 5] + fibonacci[5] * fibonacci[n - 6];
 ...
 fibonacci[n] = fibonacci[k + 1] * fibonacci[n - k] + fibonacci[k] * fibonacci[n - (k + 1)];
 
 분할 정복을 위해
 n이 짝수일 때와 홀수일 때를 구분해서 풀이
 n이 짝수 일 때 k에 n / 2를 대입해보면,
 fibonacci[n] = fibonacci[n / 2 + 1] * fibonacci[n / 2] + fibonacci[n / 2] * fibonacci[n / 2 - 1];
 
 n이 홀수일 때 k에 (n - 1) / 2을 대입해보면,
 fibonacci[n] = fibonacci[(n + 1) / 2] * fibonacci[(n + 1) / 2] + fibonacci[(n - 1) / 2] * fibonacci[(n - 1) / 2];
 fibonacci[n] = fibonacci[(n + 1) / 2]^2 + fibonacci[(n - 1] / 2]^2;
 
 **n, num 혼동하여 사용해서 메모리 초과 발생** 
 재귀에서 전역변수와 헷갈리지 않게 주의할 것
 */
