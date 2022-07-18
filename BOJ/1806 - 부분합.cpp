//
//  1806 - 부분합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/17.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, S;
int ans = 1e8 + 1;
int d[100001];

int main(){
    FASTIO
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        d[i] = d[i - 1] + tmp;
    }
    int en = 0;
    for(int st = 0; st <= N; st++){
        while(en <= N && d[en] - d[st] < S) en++;
        if(en > N) break;
        ans = min(en - st, ans);
    }
    if(ans == 1e8 + 1) ans = 0;
    cout << ans;
    return 0;
}
