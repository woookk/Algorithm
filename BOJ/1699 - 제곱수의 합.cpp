//
//  1699 - 제곱수의 합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/23.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[100001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++){
        d[i] = i;
        for(int j = 1; j * j <= i; j++){
            d[i] = min(d[i], d[i - j * j] + 1);
        }
    }
    cout << d[N];
    return 0;
}
