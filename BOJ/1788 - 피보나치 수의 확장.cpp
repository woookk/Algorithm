//
//  1788 - 피보나치 수의 확장.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/23.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int d[1000010];
int mod = 1e9;

int main(void){
    FASTIO;
  
    cin >> n;
    d[0] = 0; d[1] = 1;
    if(n >= 0) {
        for(int i = 2; i <= n; ++i) {
            d[i] = (d[i-1] + d[i-2]) % mod;
        }
    }
    else {
        n = abs(n);
        for(int i = 2; i <= n; ++i) {
            d[i] = (d[i-2] - d[i-1]) % mod;
        }
    }
    if(d[n] > 0) cout << "1\n";
    else if(d[n] < 0) cout << "-1\n";
    else cout << "0\n";
    cout << abs(d[n]);
}
