//
//  11399 - ATM.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/28.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;
int p[1001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    sort(p, p + N);
    for(int i = 0; i < N; i++){
        ans += (p[i] * (N - i));
    }
    cout << ans;
    return 0;
}
