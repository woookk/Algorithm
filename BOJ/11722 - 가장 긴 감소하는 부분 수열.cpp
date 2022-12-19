//
//  11722 - 가장 긴 감소하는 부분 수열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/12/19.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int A[1001];
int d[1001];
int ans;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= N; i++) {
        d[i] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[j] > A[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    
    ans = d[1];
    for (int i = 1; i <= N; i++) {
        ans = max(ans, d[i]);
    }
    
    cout << ans;
    return 0;
}

