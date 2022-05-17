//
//  1912 - 연속합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/17.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int a[100001], d[100001];

int main(){
    FASTIO;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    d[1] = a[1];
    for(int i = 2; i <= n; i++){
        d[i] = max(d[i - 1] + a[i], a[i]);
    }
    cout << *max_element(d + 1, d + n + 1);
    return 0;
}
