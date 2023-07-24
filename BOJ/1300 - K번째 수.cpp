//
//  1300 - K번째 수.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
int N, k;
ll ans;

ll countLessOrEqual(ll mid) {
    ll cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i > mid) break;
        if (mid / i > N) {
            cnt += N;
        }
        else {
            cnt += mid / i;
        }
    }
    return cnt;
}

int main() {
    FASTIO
    cin >> N >> k;
    
    ll low = 1, high = (ll)N * N;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (countLessOrEqual(mid) < k) low = mid + 1;
        else {
            high = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
    return 0;
}

/*
 크기가 N×N인 배열 A. 배열에 들어있는 수 A[i][j] = i×j
 이 수를 일차원 배열 B에 넣으면 B의 크기는 N*N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.
 
 1, N * N을 low, high로 잡고 mid = (low + high) / 2, mid보다 작거나 같은 개수 구하는 풀이
 mid보다 작거나 같은 개수 구하는데 N만큼 소요되므로 시간복잡도 O(N * logK)
 */
