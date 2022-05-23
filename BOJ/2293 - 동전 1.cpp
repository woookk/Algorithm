//
//  2293 - 동전 1.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/23.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, k;
int c[101], d[10001];

int main(){
    FASTIO;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    d[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = c[i]; j <= k; j++){
            d[j] += d[j - c[i]];
        }
    }
    cout << d[k] << "\n";
    return 0;
}
