//
//  2217 - 로프.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/26.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int l[100001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> l[i];
    }
    sort(l, l + N);
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, l[N - i] * i);
    }
    cout << ans;
    return 0;
}
