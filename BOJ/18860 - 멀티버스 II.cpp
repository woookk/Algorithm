//
//  18860 - 멀티버스 II.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int M, N, ans;
vector<vector<int>> space, uni, idx;

int main(){
    FASTIO
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        vector<int> v(N);
        for(int j = 0; j < N; j++){
            cin >> v[j];
        }
        space.push_back(v);
        uni.push_back(v);
        idx.push_back(v);
    }
    
    for(int i = 0; i < M; i++){
        sort(uni[i].begin(), uni[i].end());
        uni[i].erase(unique(uni[i].begin(), uni[i].end()), uni[i].end());
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < space[i].size(); j++){
            idx[i][j] = lower_bound(uni[i].begin(), uni[i].end(), space[i][j]) - uni[i].end();
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = i + 1; j < M; j++){
            if(idx[i] == idx[j]) ans++;
        }
    }
    
    cout << ans;
    return 0;
}
