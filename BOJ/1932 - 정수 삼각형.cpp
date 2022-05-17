//
//  1932 - 정수 삼각형.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/16.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int a[505][505], d[505][505];

int main(){
    FASTIO;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }
    d[1][1] = a[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
        }
    }
    cout << *max_element(d[n] + 1, d[n] + n + 1);
    return 0;
}
