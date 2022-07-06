//
//  11051 - 이항 계수 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int d[1001][1001];
const int mod = 10007;

int main(){
    FASTIO
    cin >> N >> K;
    for(int i = 1; i <= 1000; i++){
        d[i][0] = d[i][i] = 1;
        for(int j = 1; j < i; j++){
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % mod;
        }
    }
    cout << d[N][K];
    return 0;
}
