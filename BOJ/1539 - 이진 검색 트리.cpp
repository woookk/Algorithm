//
//  1539 - 이진 검색 트리.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/06.
//

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N;
ll ans;
int h[250001];
set<int> s;

int main(){
    FASTIO
    cin >> N;
    while(N--){
        int key;
        cin >> key;
        
        auto it = s.lower_bound(key);
        
        int left, right;
        if(it != s.begin()){
            auto left_it = it;
            left = h[*(--left_it)];
        }
        else{
            left = 0;
        }
        
        if(it != s.end()){
            right = h[*it];
        }
        else {
            right = 0;
        }
        h[key] = max(left, right) + 1;
        s.insert(key);
        ans += h[key];
    }
    cout << ans;
    return 0;
}
