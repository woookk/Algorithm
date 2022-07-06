//
//  6064 - 카잉 달력.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;

int GCD(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b){
    return (a * b) / GCD(a, b);
}

int solve(int m, int n, int x, int y){
    if(x == m) x = 0;
    if(y == n) y = 0;
    int l = LCM(n, m);
    for(int i = x; i <= l; i += m){
        if(i == 0) continue;
        if(i % n == y){
            return i;
        }
    }
    return -1;
}

int main(){
    FASTIO;
    cin >> T;
    while(T--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << "\n";
    }
    return 0;
}
