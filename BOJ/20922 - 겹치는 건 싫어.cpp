//
//  20922 - 겹치는 건 싫어.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
int a[200001];
int cnt[100001];
int ans;

int main(){
    FASTIO
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    cnt[a[0]] = 1;
    int en = 0;
    for(int st = 0; st < N; st++){
        while(en < N - 1 && cnt[a[en + 1]] < K){
            en++;
            cnt[a[en]]++;
        }
        ans = max(ans, en - st + 1);
        cnt[a[st]]--;
    }
    cout << ans;
    return 0;
}
