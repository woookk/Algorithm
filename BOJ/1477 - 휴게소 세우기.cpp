//
//  1477 - 휴게소 세우기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/16.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, L, ans;
int a[51];

bool isPossible(int upper){
    int cnt = 0;
    int prev = 0;
    for(int i = 0; i <= N; i++){
        int dist;
        if(i == N)
            dist = L - prev;
        else
            dist = a[i] - prev;
        if(dist > upper){
            cnt += (dist - 1) / upper;
        }
        prev = a[i];
    }
    if(cnt <= M) return true;
    return false;
}

int main(){
    FASTIO
    cin >> N >> M >> L;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    
    int st = 1;
    int en = L;
    ans = 1000;
    while(st <= en){
        int mid = (st + en) / 2;
        if(isPossible(mid)){
            en = mid - 1;
            ans = min(mid, ans);
        }
        else {
            st = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
