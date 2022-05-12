//
//  7795 - 먹을 것인가 먹힐 것인가.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T, N, M;

int main(){
    FASTIO;
    cin >> T;
    while(T--){
        cin >> N >> M;
        vector<pair<int, int>> v;
        int a, b;
        for(int i = 0; i < N; i++){
            cin >> a;
            v.push_back({a, 0});
        }
        for(int i = 0; i < M; i++){
            cin >> b;
            v.push_back({b, 1});
        }
        sort(v.begin(), v.end());
        int cnt = 0, ans = 0;
        for(int i = 0; i < N + M; i++){
            if(v[i].second == 0)
                ans += cnt;
            else
                cnt++;
        }
        cout << ans << "\n";
    }
    return 0;
}
