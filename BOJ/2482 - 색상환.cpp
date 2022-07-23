//
//  2482 - 색상환.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/24.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int d[1001][1001];
const int mod = 1e9 + 3;

int main(){
    FASTIO
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        d[i][1] = i;
    }
    for(int i = 4; i <= N; i++){
        for(int j = 2; j <= K; j++){
            if(j > i / 2) break;
            d[i][j] = (d[i - 1][j] + d[i - 2][j - 1]) % mod;
        }
    }
    cout << d[N][K];
    return 0;
}
