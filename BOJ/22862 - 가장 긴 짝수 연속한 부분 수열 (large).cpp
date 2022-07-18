//
//  22862 - 가장 긴 짝수 연속한 부분 수열 (large).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/18.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K, ans;
int a[1000001];

int main(){
    FASTIO
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int en = 0;
    int cnt = a[0] % 2;
    for(int st = 0; st < N; st++){
        while(en < N - 1 && (cnt < K || a[en + 1] % 2 == 0)){
            if(a[en + 1] % 2) cnt++;
            en++;
        }
        ans = max(ans, en - st + 1 - cnt);
        if(a[st] % 2) cnt--;
    }
    cout << ans;
    return 0;
}
