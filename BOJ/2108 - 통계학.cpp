//
//  2108 - 통계학.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/25.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, sum;
int num[500001];
int cnt[8001];
int most;
int mostidx;

int main(){
    FASTIO
    cin >> N;
    int mn = 4001, mx = -4001;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        sum += num[i];
        mn = min(mn, num[i]);
        mx = max(mx, num[i]);
        cnt[4000 + num[i]]++;
    }
    int mostcnt = 0;
    for(int i = 0; i < 8001; i++){
        if(most < cnt[i]){
            most = cnt[i];
            mostidx = i - 4000;
            mostcnt = 1;
        }
        else if (most == cnt[i]){
            mostcnt++;
            if(mostcnt == 2){
                mostidx = i - 4000;
            }
        }
    }
    sort(num, num + N);
    if(round(sum / (double)N) == -0){
        cout << 0 << "\n";
    }
    else {
        cout << round(sum / (double)N) << "\n";
    }
    cout << num[N / 2] << "\n";
    cout << mostidx << "\n";
    cout << mx - mn << "\n";
    return 0;
}
