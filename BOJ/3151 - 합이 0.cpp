//
//  3151 - 합이 0.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/14.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
long long ans;
int A[10001];

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    for(int i = 0; i < N - 2; i++){
        for(int j = i + 1; j < N - 1; j++){
            int lower = lower_bound(A + j + 1, A + N, -(A[i] + A[j])) - A;
            int upper = upper_bound(A + j + 1, A + N, -(A[i] + A[j])) - A;
            ans += upper - lower;
        }
    }
    cout << ans;
    return 0;
}
