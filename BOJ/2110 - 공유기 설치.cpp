//
//  2110 - 공유기 설치.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/16.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, C, ans;
int x[200001];

bool ispossible(int d){
    int cnt = 1;
    int prev = x[0];
    for(int i = 1; i < N; i++){
        if(x[i] - prev >= d){
            cnt++;
            prev = x[i];
        }
    }
    if(cnt >= C) return true;
    return false;
}

int main(){
    FASTIO
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    sort(x, x + N);
    int st = 1;
    int en = x[N - 1] - x[0];
    while(st <= en){
        int mid = (st + en) / 2;
        if(ispossible(mid)){
            ans = max(ans, mid);
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
        
    }
    cout << ans;
    return 0;
}
