//
//  30022 - 행사 준비.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/26.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const int MAX = 1e5 + 5;

ll ans;
int N, A, B;
int p[MAX], q[MAX];
pair<int, int> diff[MAX];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first > b.first) return true;
    return false;
}

int main() {
    FASTIO
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) {
        cin >> p[i] >> q[i];
        diff[i] = { abs(p[i] - q[i]), i };
    }
    
    sort(diff + 1, diff + N + 1, cmp);
    
    for (int i = 1; i <= N; i++) {
        auto [costDiff, idx] = diff[i];
        if (A <= 0) {
            ans += q[idx];
            continue;
        }
        if (B <= 0) {
            ans += p[idx];
            continue;
        }
        
        if (p[idx] < q[idx]) {
            ans += p[idx];
            A--;
        }
        else {
            ans += q[idx];
            B--;
        }
    }
    cout << ans;
    return 0;
}

/*
 동하와 지원이는 행사를 준비하고 있다. 행사를 위해 N 종류의 물건이 한 개씩 필요하기 때문에 동하가 A개를, 지원기 B개를 나눠서 준비
 근처에 있는 상점 1, 2에서 N 종류의 물건을 모두 판매하고 있다. 같은 물건이라도 상점에서 판매하는 가격이 다를 수 있기 때문에 동하는 상점 1에서 지원이는 상점 2에서 물건을 구입하려고 한다.
 
 상점 1에서는 물건을 p1, ..., pn원에 판매하고, 상점 2에서는 q1, ..., qn원에 판매
 동하가 상점 1에서 A개의 물건을, 지원이가 상점 2에서 B개의 물건을 구입해서 N종류의 물건을 모두 구매하는데 필요한 최소 비용을 구해보자.
 
 가격 차이에 따라 정렬 진행하고 가격차이가 큰 물건부터 A가 살지 B가 살지 판단.
 */
