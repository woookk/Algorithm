//
//  2467 - 용액.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main(){
    FASTIO
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int ans1 = 1e9 + 1;
    int ans2 = 1e9 + 1;
    for(int i = 0; i < N; i++){
        int idx = lower_bound(v.begin(), v.end(), -1 * v[i]) - v.begin();
        if(idx + 1 < N && i != idx + 1 && abs(v[i] + v[idx + 1]) < abs(ans1 + ans2)){
            ans1 = v[i];
            ans2 = v[idx + 1];
        }
        if(idx < N && i != idx && abs(v[i] + v[idx]) < abs(ans1 + ans2)){
            ans1 = v[i];
            ans2 = v[idx];
        }
        if(idx != 0 && i != idx - 1 && abs(v[i] + v[idx - 1]) < abs(ans1 + ans2)){
            ans1 = v[i];
            ans2 = v[idx - 1];
        }
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
