//
//  2156 - 포도주 시식.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/20.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int a[10001], d[10001];

int main(){
    FASTIO;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    d[1] = a[1]; d[2] = a[1] + a[2];
    for(int i = 3; i <= n; i++){
        d[i] = max({d[i - 1], d[i -2] + a[i], d[i - 3] + a[i - 1] + a[i]});
    }
    cout << d[n];
    return 0;
}
