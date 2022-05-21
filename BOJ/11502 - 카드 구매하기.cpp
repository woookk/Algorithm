//
//  11502 - 카드 구매하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/21.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int p[10001], d[10001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> p[i];
        d[i] = p[i];
    }
    for(int i = 2; i <= N; i++){
        
        for(int j = 1; j < i; j++){
            d[i] = max(d[j] * (i / j) + d[i % j], d[i]);
        }
    }
    cout << d[N];
    return 0;
}
