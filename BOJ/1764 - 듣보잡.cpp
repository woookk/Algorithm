//
//  1764 - 듣보잡.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int cnt;
vector<string> v, ans;
string tmp;

int main(){
    FASTIO
    cin >> N >> M;
    for(int i = 0; i < N + M; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N + M - 1; i++){
        if(v[i] == v[i + 1]){
            ans.push_back(v[i]);
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(auto c : ans){
        cout << c << "\n";
    }
    return 0;
}
