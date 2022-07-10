//
//  3343 - 장미.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/10.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
ll N;
ll A, B, C, D;

ll GCD(ll a, ll b){
    while(b){
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll LCM(ll a, ll b){
    return a * b / GCD(a, b);
}

int main(){
    FASTIO
    cin >> N >> A >> B >> C >> D;
    ll l = LCM(A, C);
    if(D * A >= B * C){
        swap(A, C);
        swap(B, D);
    }
    int a_cnt = 0;
    ll minimum_amount = 1e18 + 1;
    while(A * a_cnt < l) {
        if(N <= A * a_cnt) {
            if(B * a_cnt < minimum_amount)
                minimum_amount = B * a_cnt;
            break;
        }
        ll remain = N - A * a_cnt;
        ll c_cnt = (remain - 1) / C + 1;
        
        ll cost = B * a_cnt + D * c_cnt;
        if(cost < minimum_amount)
            minimum_amount = cost;

        a_cnt++;
    }
    
    cout << minimum_amount;
    return 0;
}
