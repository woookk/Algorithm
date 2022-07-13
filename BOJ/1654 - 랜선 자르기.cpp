//
//  1654 - 랜선 자르기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/13.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int K, N;
int a[10001];

bool solve(ll x){
    long long cur = 0;
    for(int i =  0; i < K; i++){
        cur += a[i] / x;
    }
    return cur >= N;
}

int main(){
    FASTIO
    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> a[i];
    }
    ll st = 1;
    ll en = 0x7fffffff;
    while(st < en){
        ll mid = (st + en + 1) / 2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
    return 0;
}
