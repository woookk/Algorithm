//
//  1351 - 무한 수열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/30.
//

#include <iostream>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

ll N, P, Q;
unordered_map<ll, ll> map;

ll solve(ll n){
    if(n == 0) return 1;
    
    ll& ret = map[n];
    if(ret != 0) return ret;
    
    return ret = solve(n / P) + solve(n / Q);
}

int main(){
    FASTIO
    cin >> N >> P >> Q;
    cout << solve(N);
    return 0;
}
