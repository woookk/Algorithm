//
//  1476 - 날짜 계산.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/08.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int GCD(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b){
    return a * b / GCD(a, b);
}
int main(){
    FASTIO
    int E, S, M;
    cin >> E >> S >> M;
    E--; S--; M--;
    int tmp = E;
    while(tmp % 28 != S) tmp += 15;
    int lcm = LCM(15, 28);
    while(tmp % 19 != M) tmp += lcm;
    cout << tmp + 1;
    return 0;
}
