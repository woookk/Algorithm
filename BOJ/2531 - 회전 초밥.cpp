//
//  2531 - 회전 초밥.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/18.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, d, k, c;
int a[30001];
int kind[3001];
int ans;

int main() {
    FASTIO
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int tot = 0;
    for(int i = N - k; i < N; i++){
        if(kind[a[i]] == 0)
            tot++;
        kind[a[i]]++;
    }
    for(int i = 0; i < N; i++){
        if(kind[a[i]] == 0)
            tot++;
        kind[a[i]]++;
        int st = i - k;
        if(st < 0)
            st += N;
        if(kind[a[st]] == 1)
            tot--;
        kind[a[st]]--;
        ans = max(ans, tot + (kind[c] == 0));
    }
    cout << ans;
    return 0;
}
