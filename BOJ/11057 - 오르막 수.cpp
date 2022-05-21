//
//  11057 - 오르막 수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/21.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[1001][10];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i <= 9; i++){
        d[1][i] = 1;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = j; k <= 9; k++){
                d[i][j] += d[i - 1][k] % 10007;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += d[N][i] % 10007;
    }
    cout << ans % 10007;
    return 0;
}
