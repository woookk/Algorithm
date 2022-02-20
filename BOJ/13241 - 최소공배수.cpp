//
//  13241 - 최소공배수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/20.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

long long GCD(long long a, long long b){
    while(b){
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FASTIO;
    long long A, B;
    cin >> A >> B;
    long long ans = A * B / GCD(A, B);
    cout << ans;
}
