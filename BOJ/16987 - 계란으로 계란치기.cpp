//
//  16987 - 계란으로 계란치기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/08.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans, cnt;
int d[8];
int w[8];

void func(int k){
    if(k == N){
        ans = max(ans, cnt);
        return;
    }
    if(d[k] <= 0 || cnt == N - 1){
        func(k + 1);
        return;
    }
        
    for(int i = 0; i < N; i++){
        if(i == k || d[i] <= 0) continue;
        d[k] -= w[i];
        d[i] -= w[k];
        if(d[k] <= 0) cnt++;
        if(d[i] <= 0) cnt++;
        func(k + 1);
        if(d[k] <= 0) cnt--;
        if(d[i] <= 0) cnt--;
        d[k] += w[i];
        d[i] += w[k];
    }
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> d[i] >> w[i];
    }
    func(0);
    cout << ans;
    return 0;
}
