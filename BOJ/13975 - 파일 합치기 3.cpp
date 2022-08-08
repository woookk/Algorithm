//
//  13975 - 파일 합치기 3.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/08.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int TC;

int main(){
    FASTIO
    cin >> TC;
    while(TC--){
        int K;
        cin >> K;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll ans = 0;
        while(K--){
            int temp;
            cin >> temp;
            pq.push(temp);
        }
        while(pq.size() > 1){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ans += (a + b);
            pq.push(a + b);
        }
        cout << ans << "\n";
    }
    return 0;
}
