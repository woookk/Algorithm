//
//  1990 - 소수인팰린드롬.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/09.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MX 10000001
int a, b;

bool isPrime[MX];

void sieve() {
    for (int i = 2; i < MX; i++) {
        isPrime[i] = 1;
    }
    
    for (int i = 2; i <= 4000; i++) {
        if (isPrime[i] == 0) continue;
        for (int j = i * i; j < MX; j += i) {
            if (isPrime[j]) isPrime[j] = 0;
        }
    }
}

int main() {
    FASTIO
    cin >> a >> b;
    sieve();

    for (int i = a; i <= min(b, 10000000); i++) {
        if (!isPrime[i]) continue;
        string str = to_string(i);
        int len = (int) str.length();
        bool isPalindrome = true;
        for (int j = 0; j < len / 2; j++) {
            if (str[j] != str[len - 1 - j]) {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome) {
            cout << i << "\n";
        }
    }
    cout << -1 << "\n";
    return 0;
}
