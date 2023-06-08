//
//  18186 - 라면 사기 (Large).cpp
//  Cpp
//
//  Created by 민병욱 on 2023/06/08.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MX 1000005
typedef long long ll;

int n, B, C;
ll a[MX], a2[MX], a3[MX];
ll ans;

int main() {
    FASTIO
    cin >> n >> B >> C;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    if (B <= C) {
        for (int i = 1; i <= n; i++) {
            ans += a[i] * B;
        }
    } else {
        for (int i = 2; i <= n; i++) {
            a2[i] = min(a[i], a[i - 1]);
            a[i] -= a2[i];
            a[i - 1] -= a2[i];
            a3[i] = min(a[i], a2[i - 1]);
            a[i] -= a3[i];
            a2[i - 1] -= a3[i];
        }
        for (int i = 1; i <= n; i++) {
            ans += a[i] * B + a2[i] * (B + C) + a3[i] * (B + 2 * C);
        }
    }
    cout << ans;
    return 0;
}

/*
 N개의 라면 공장에서 i번 공장에서 정확하게 Ai개의 라면 구매
 라면 구매 -> 세 가지 방법
 1. i번에서 라면 하나 구매 - B원
 2. i번, i+1번에서 라면 하나씩 구매 - B + C원
 3. i번, i+1번, i+2번에서 라면 하나씩 구매 - B + 2C원
 
 B <= C일 경우
 최소의 비용으로 라면을 구매하려면 각각 개별 구매
 
 B > C인 경우
 최소의 비용으로 라면을 구매하려면 3개씩 살 수 있는 만큼 최대로 구매 -> 2개씩 살 수 있는 만큼 최대로 구매 -> 개별 구매
 */
