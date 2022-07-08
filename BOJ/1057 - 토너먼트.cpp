//
//  1057 - 토너먼트.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/08.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
int N, a, b;

int main(){
    FASTIO
    cin >> N >> a >> b;
    if(a > b) swap(a, b);
    vector<int> v;
    for(int i = 1; i <= N; i++) v.push_back(i);
    
    int ans = 0;
    while(v.size() > 1){
        ans++;
        vector<int> nxt;
        for(int i = 0; i < v.size() - 1; i += 2){
            int x = v[i], y = v[i + 1];
            if(x == a && y == b){
                cout << ans;
                return 0;
            }
            if(y == a || y == b) nxt.push_back(y);
            else nxt.push_back(x);
        }
        if(v.size() % 2 == 1) nxt.push_back(v.back());
        v = nxt;
    }
    return 0;
}
