//
//  14921 - 용액 합성하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/15.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int A[100001];

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int ans1 = 1e9 + 1;
    int ans2 = 1e9 + 1;
    for(int i = 0; i < N; i++){
        int idx = lower_bound(A, A + N, -A[i]) - A;
        if(idx + 1 < N && i != idx + 1 && abs(A[i] + A[idx + 1]) < abs(ans1 + ans2)){
            ans1 = A[i];
            ans2 = A[idx + 1];
        }
        if(idx < N && i != idx && abs(A[i] + A[idx]) < abs(ans1 + ans2)){
            ans1 = A[i];
            ans2 = A[idx];
        }
        if(idx != 0 && i != idx - 1 && abs(A[i] + A[idx - 1]) < abs(ans1 + ans2)){
            ans1 = A[i];
            ans2 = A[idx - 1];
        }
    }
    cout << ans1 + ans2;
    return 0;
}
