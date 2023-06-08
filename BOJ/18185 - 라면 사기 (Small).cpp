//
//  18185 - 라면 사기 (Small).cpp
//  Cpp
//
//  Created by 민병욱 on 2023/06/07.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int a[10005], a2[10005], a3[10005];
int ans;

int main() {
    FASTIO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 2; i <= n; i++) {
        a2[i] = min(a[i], a[i - 1]);
        a[i] -= a2[i];
        a[i - 1] -= a2[i];
        a3[i] = min(a[i], a2[i - 1]);
        a[i] -= a3[i];
        a2[i - 1] -= a3[i];
    }
    
    for (int i = 1; i <= n; i++) {
        ans += a[i] * 3 + a2[i] * 5 + a3[i] * 7;
    }
    cout << ans;
    return 0;
}

/*
 N개의 라면 공장에서 i번 공장에서 정확하게 Ai개의 라면 구매
 라면 구매 -> 세 가지 방법
 1. i번에서 라면 하나 구매 - 3원
 2. i번, i+1번에서 라면 하나씩 구매 - 5원
 3. i번, i+1번, i+2번에서 라면 하나씩 구매 - 7원
 최소의 비용으로 라면 구매하려면 3개씩 살 수 있는 만큼 최대 -> 2개씩 살 수 있는 만큼 최대 -> 개별 구매
 */
