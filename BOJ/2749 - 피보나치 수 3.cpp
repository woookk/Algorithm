//
//  2749 - 피보나치 수 3.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/13.
//

#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const int MOD = 1e6;
const int MAX = 15 * 1e5;

ll n;

int main() {
    FASTIO
    cin >> n;
    vector<int> fibonacci(MAX + 1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < MAX + 1; i++) {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % MOD;
    }
    cout << fibonacci[n % MAX];
    return 0;
}

/*
 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
 이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n >= 2)가 된다.
 n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성 (n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력)
 
 
 **피사노 주기를 활용해서 문제를 풀이할 수 있다. 피사노 주기의 성질에서 m = 10^n (n > 2)일 때 피사노 주기 K(m) = 15 * 10^(n - 1)이다.**
 
 다이나믹 프로그래밍을 이용하여 하나의 피사노 주기만 알면 답을 알 수 있다.
 */
