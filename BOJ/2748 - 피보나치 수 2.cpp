//
//  2748 - 피보나치 수 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/13.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

long long fibo(int N)
{
    long long f[100];
    f[0] = 0; f[1] = 1;
    for(int i = 2; i <= N; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[N];
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}
