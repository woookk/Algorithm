//
//  1931 - 회의실 배정.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/26.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
pair<int, int> s[100001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i].second >> s[i].first;
    }
    sort(s, s + N);
    int ans = 0;
    int t = 0;
    for(int i = 0; i < N; i++){
        if(t > s[i].second) continue;
        ans++;
        t = s[i].first;
    }
    cout << ans;
    return 0;
}
