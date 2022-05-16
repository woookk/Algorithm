//
//  11727 - 2×n 타일링 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/16.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int d[1001];

int main(){
    FASTIO;
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for(int i = 3; i <= n; i++){
        d[i] = (d[i - 1] + d[i - 2] * 2) % 10007;
    }
    cout << d[n];
    return 0;
}
