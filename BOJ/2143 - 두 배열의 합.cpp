//
//  2143 - 두 배열의 합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int T, n, m;
ll ans;
int A[1001], B[1001];
int dpA[1001], dpB[1001];
vector<int> subA, subB;

int main(){
    FASTIO
    cin >> T;
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        dpA[i] = dpA[i - 1] + A[i];
    }
    
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> B[i];
        dpB[i] = dpB[i - 1] + B[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            subA.push_back(dpA[i] - dpA[j]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < i; j++){
            subB.push_back(dpB[i] - dpB[j]);
        }
    }
    sort(subA.begin(), subA.end());
    sort(subB.begin(), subB.end());
    for(int i = 0; i < subA.size(); i++){
        int lower = lower_bound(subB.begin(), subB.end(), T - subA[i]) - subB.end();
        int upper = upper_bound(subB.begin(), subB.end(), T - subA[i]) - subB.end();
        ans += upper - lower;
    }
    cout << ans;
    return 0;
}
