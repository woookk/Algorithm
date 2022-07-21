//
//  2283 - 구간 자르기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/20.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K, ans1, ans2;
int num[1000001];

int main(){
    FASTIO
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int st, en;
        cin >> st >> en;
        for(int j = st + 1; j <= en; j++) num[j]++;
    }
    int st = 0, en = 0;
    int sum = 0;
    while(en < 1000001){
        if(sum > K){
            st++;
            sum -= num[st];
        }
        else if (sum < K){
            en++;
            sum += num[en];
        }
        else {
            ans1 = st; ans2 = en;
            break;
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}
