//
//  1850 - 최대공약수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/20.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int GCD(long long a, long long b){
    while(b){
        long long c = a % b;
        a = b;
        b = c;
    }
    return (int)a;
}

int main(){
    FASTIO;
    long long A, B;
    cin >> A >> B;
    int N = GCD(A, B);
    string s = "";
    for(int i = 0; i < N; i++){
        s += "1";
    }
    cout << s;
    return 0;
}
