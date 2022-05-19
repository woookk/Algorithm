//
//  10844 - 쉬운 계단 수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/19.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[101][10];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= 9; i++){
        d[1][i] = 1;
    }
    
    for(int i = 2; i <= N; i++){
        for(int k = 0; k <= 9; k++){
            if(k != 0) d[i][k] += d[i - 1][k - 1];
            if(k != 9) d[i][k] += d[i - 1][k + 1];
            d[i][k] %= 1000000000;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += d[N][i];
    }
    ans %= 1000000000;
    cout << ans;
    return 0;
}
