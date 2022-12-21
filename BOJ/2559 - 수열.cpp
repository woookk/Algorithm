//
//  2559 - 수열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/12/21.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int sum, ans;
int arr[100001];


int main() {
    FASTIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int st = 0; st < K; st++) {
        sum += arr[st];
    }
    ans = sum;
    
    for (int st = 1; st <= N - K; st++) {
        sum -= arr[st - 1];
        sum += arr[st + K - 1];
        ans = max(sum, ans);
    }
    
    cout << ans;
    return 0;
}
