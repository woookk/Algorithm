//
//  1202 - 보석 도둑.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/04.
//

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
typedef long long ll;

int N, K;
ll ans;
pair<int, int> jewel[300001];
multiset<int> bag;

int main(){
    FASTIO
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> jewel[i].Y >> jewel[i].X;
    }
    sort(jewel, jewel + N);
    for(int i = 0; i < K; i++){
        int w;
        cin >> w;
        bag.insert(w);
    }
    for(int i = N - 1; i >= 0; i--){
        int v = jewel[i].X;
        int m = jewel[i].Y;
        auto it = bag.lower_bound(m);
        if(it == bag.end()) continue;
        ans += v;
        bag.erase(it);
    }
    cout << ans;
    return 0;
}
