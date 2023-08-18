//
//  1557 - 제곱 ㄴㄴ.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const int MAX = (int)sqrt(INT_MAX);

int K, numberOfNoneSquareNumber;
vector<bool> isPrime(MAX);
vector<ll> squareNumber;

void sieve() {
    for (int i = 2; i <= MAX; i++) {
        isPrime[i] = true;
    }
    
    for (int i = 2; i <= MAX; i++) {
        if (!isPrime[i]) continue;
        
        for (int j = i * i; j <= MAX; j += i) {
            if (!isPrime[j]) continue;
            isPrime[j] = false;
        }
    }
    
    for (int i = 1; i <= MAX; i++) {
        if (isPrime[i]) squareNumber.push_back(i * i);
    }
}

ll recursiveCalc(ll mid, int start, ll product, int sign) {
    if (start == squareNumber.size() || product * squareNumber[start] > mid) {
        return 0;
    }

    ll result = sign * (mid / (product * squareNumber[start]));
    result += recursiveCalc(mid, start + 1, product, sign);
    result += recursiveCalc(mid, start + 1, product * squareNumber[start], -sign);

    return result;
}

ll getNumberOfNoneSquareNumber(ll mid) {
    ll result = recursiveCalc(mid, 0, 1, 1);
    return mid - result;
}


int main() {
    FASTIO
    cin >> K;
    sieve();
    
    ll low = K, high = K * 2, mid = (low + high) / 2;
    while (low <= high) {
        mid = (low + high) / 2;
        ll count = getNumberOfNoneSquareNumber(mid);
        if (count < K) {
            low = mid + 1;
        }
        else if (count == K) {
            while (getNumberOfNoneSquareNumber(mid) == K) {
                mid--;
            }
            cout << ++mid;
            return 0;
        }
        else {
            high = mid - 1;
        }
    }
}

/*
 어떤수 N이 1이 아닌 제곱수로 나누어지지 않을 때, 이 수를 제곱ㄴㄴ수라고 한다. 제곱수는 4, 9, 16, 25와 같은 것이고, 제곱ㄴㄴ수는 1, 2, 3, 5, 6, 7, 10, 11, 13, ...과 같은 수이다.
 K가 주어졌을 때, K번째 제곱ㄴㄴ수를 구하는 프로그램을 작성
 
 에라토스테네스의 체 활용해서 소수 구한 후
 소수 제곱 수의 개수를 구한 후 그것들을 제외해주는 방식으로 제곱 ㄴㄴ수를 구할 수 있다.
 제곱 ㄴㄴ수를 구한 후 이분 탐색을 활용하여 K번째 제곱ㄴㄴ수 찾을 수 있다.
 
 재귀함수를 이용하여 제곱 수의 개수를 구할 때 겹치는 부분을 제외해주는 방식으로 구현.
 
 */
