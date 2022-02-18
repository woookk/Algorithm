//
//  5347 - LCM.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/18.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

long long GCD(long long a, long long b){
    
    long long c;
    while (b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FASTIO;
    int T;
    cin >> T;
    while(T--){
        long long a, b;
        cin >> a >> b;
        cout << a * b / GCD(a, b) << "\n";
    }
    return 0;
}
