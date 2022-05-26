//
//  11047 - 동전 0.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/26.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int A[11];

int main(){
    FASTIO;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int ans = 0;
    for(int i = N - 1; i >= 0; i--){
        ans += K / A[i];
        K %= A[i];
    }
    cout << ans;
    return 0;
}
