//
//  10794 - 모든 순열.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/17.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 8;

int N;
vector<int> arr(MAX);
vector<bool> isUsed(MAX + 1, 0);

void print() {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void solve(int depth) {
    if (depth == N) {
        print();
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (isUsed[i]) continue;
        isUsed[i] = true;
        arr[depth] = i;
        solve(depth + 1);
        isUsed[i] = false;
    }
}

int main() {
    FASTIO
    cin >> N;
    solve(0);
    return 0;
}

/*
 N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전 순으로 출력하는 프로그램을 작성
 
 백트래킹 이용하여 풀이
 */
