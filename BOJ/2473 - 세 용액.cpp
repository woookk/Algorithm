//
//  2473 - 세 용액.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/15.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N;
ll A[5001];
ll ans[3];

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    
    ans[0] = ans[1] = ans[2] = 1e9 + 1;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int idx = lower_bound(A, A + N, -A[i] - A[j]) - A;
            for(int k = idx - 2; k <= idx + 2; k++){
                if(k == i || k == j) continue;
                if(k < 0 || k >= N) continue;
                if(abs(ans[0] + ans[1] + ans[2]) > abs(A[i] + A[j] + A[k]))
                    tie(ans[0], ans[1], ans[2]) = {A[i], A[j], A[k]};
            }
        }
    }
    sort(ans, ans + 3);
    cout << ans[0] << " " << ans[1] << " " << ans[2];
    return 0;
}
