//
//  2230 - 수 고르기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/17.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int ans = 2e9;
int a[100001];

int main(){
    FASTIO
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    
    for(int i = 0; i < N; i++){
        int idx = lower_bound(a, a + N, a[i] + M) - a;
        if(idx < N){
            ans = min(a[idx] - a[i], ans);
        }
    }
    cout << ans;
    return 0;
}
