//
//  30021 - 순열 선물하기.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/20.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 15e6 + 5;

int N;
bool isPrime[MAX];

void sieve() {
    for (int i = 2; i < MAX; i++) {
        isPrime[i] = true;
    }
    
    for (int i = 2; i < MAX; i++) {
        if (!isPrime[i]) continue;
        
        for (int j = i * 2; j < MAX; j += i) {
            if (!isPrime[j]) continue;
            isPrime[j] = false;
        }
    }
}

vector<int> findAnswer() {
    vector<int> seq;
    int sum = 0;
    
    if (N == 1) {
        cout << "YES\n";
        seq.push_back(1);
        return seq;
    }
    
    if (N == 2) {
        cout << "NO\n";
        return seq;
    }
    
    cout << "YES\n";
    for (int i = 1; i <= N; i++) {
        if (isPrime[sum + i]) {
            seq.push_back(i + 1);
            seq.push_back(i);
            sum += i;
            sum += i + 1;
            i++;
        }
        else {
            seq.push_back(i);
            sum += i;
        }
    }
    return seq;
}

int main() {
    FASTIO
    cin >> N;
    sieve();
    vector<int> ans = findAnswer();
    for (auto v: ans) {
        cout << v << " ";
    }
    return 0;
}

/*
 정수 1, 2, ... N을 가지고 있다. 가지고 있는 정수를 하루에 하나씩 N일에 걸쳐 선물.
 소수를 싫어하기 때문에 선물 받은 수의 합이 소수가 되는 날이 없도록 해야한다.
 
 정수 1, 2, ..., N을 선물하려면 어떤 순서로 선물해야 하는지 구해보자.
 
 에라토스테네스의 체를 이용하여 먼저 1500만 까지 소수를 모두 구한 후 O(N)
 
 1, 2, 3, ... 순서대로 선물하면서 현재까지 선물한 수의 합이 소수가 될 경우 뒷 순서와 바꿔주면 된다.
 최소 짝수는 소수가 아니므로 연속한 숫자가 소수일 수 없다. (2, 3제외).
 */
