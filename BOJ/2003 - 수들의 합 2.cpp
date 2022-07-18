//
//  2003 - 수들의 합 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/17.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, tot, ans;
int a[10001];

int main(){
    FASTIO
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    tot = a[0];
    int en = 0;
    for(int st = 0; st < N; st++){
        while(en < N && tot < M) {
            en++;
            if(en != N) tot += a[en];
        }
        if(en == N) break;
        if(tot == M) ans++;
        tot -= a[st];
    }
    cout << ans;
    return 0;
}
