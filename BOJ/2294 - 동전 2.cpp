//
//  2294 - 동전 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/31.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, k;
int a[101];
int d[10001];

int main(){
    FASTIO;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    fill(d, d + 10001, 100001);
    d[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = a[i]; j <= k; j++){
            d[j] = min(d[j], d[j - a[i]] + 1);
        }
    }
    if(d[k] != 100001)
        cout << d[k];
    else
        cout << -1;
    return 0;
}
