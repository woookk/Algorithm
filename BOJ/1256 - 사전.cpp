//
//  1256 - 사전.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/10.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, K;
int d[201][201];
string ans;

int main(){
    FASTIO
    cin >> N >> M >> K;
    for(int i = 1; i < 201; i++){
        d[i][0] = d[i][i] = 1;
        for(int j = 1; j < i; j++){
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
            if(d[i][j] > 1e9 + 1) d[i][j] = 1e9 + 1;
        }
    }
    if(K > d[N + M][N]){
        cout << -1;
        return 0;
    }
    int len = N + M;
    while(len--){
        if(!N){
            ans += 'z';
            M--;
            continue;
        }
        if(!M){
            ans += 'a';
            N--;
            continue;
        }
        if(d[N + M - 1][N - 1] >= K){
            ans += 'a';
            N--;
        }
        else {
            ans += 'z';
            K -= d[N + M - 1][N - 1];
            M--;
        }
    }
    cout << ans;
    return 0;
}
