//
//  2230 - 수 고르기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/17.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int ans = 2e9 + 1;
int a[100001];

int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    int en = 0;
    for(int st = 0; st < N; st++){
        while(en < N && a[en] - a[st] < M) en++;
        if(en == N) break;
        ans = min(ans, a[en] - a[st]);
    }
    cout << ans;
    return 0;
}
