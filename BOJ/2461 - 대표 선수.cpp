//
//  2461 - 대표 선수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
vector<pair<int, int>> v;
int cnt[1005];
int num = 0;

int main(){
    FASTIO
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int tmp;
            cin >> tmp;
            v.push_back({tmp, i});
        }
    }
    sort(v.begin(), v.end());
    int st = 0, en = 0;
    int ans = 0x7fffffff;
    while(en < N * M){
        if(cnt[v[en].Y] == 0) num++;
        cnt[v[en].Y]++;
        en++;
        while(num == N){
            ans = min(ans, v[en - 1].X - v[st].X);
            cnt[v[st].Y]--;
            if(cnt[v[st].Y] == 0) num--;
            st++;
        }
    }
    cout << ans;
    return 0;
}
