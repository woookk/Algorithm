//
//  1629 - 곱셈.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/03.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

long long POW(long long a, long long b, long long c){
    if(b == 1) return a % c;
    long long val = POW(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 0) return val;
    return val * a % c;
}

int main(){
    FASTIO;
    long long a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
    return 0;
}
