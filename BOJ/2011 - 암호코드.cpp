//
//  2011 - 암호코드.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/30.
//

#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string p;
int a[5001], d[5001];
const int mod = 1000000;

int main(){
    FASTIO;
    cin >> p;
    int len = (int)p.length();
    d[0] = 1;
    for(int i = 1; i <= len; i++) a[i] = p[i - 1] - '0';
    for(int i = 1; i <= len; ++i){
        if(a[i] > 0) d[i] = (d[i] + d[i-1]) % mod;
        int x = a[i - 1] * 10 + a[i];
        if(x >= 10 && x <= 26) d[i] = (d[i] + d[i - 2]) % mod;
    }
    cout << d[len];
    return 0;
}
