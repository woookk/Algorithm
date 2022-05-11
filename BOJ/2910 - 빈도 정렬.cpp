//
//  2910 - 빈도 정렬.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, C;
vector<pair<int, int>> v;

bool cmp(const pair<int ,int>& a, const pair<int, int>& b){
    return a.X > b.X;
}

int main(){
    FASTIO;
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        bool flag = false;
        for(auto& c : v){
            if(c.Y == num){
                flag = true;
                c.X++;
                break;
            }
        }
        if(!flag) v.push_back({1, num});
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(auto c: v){
        while (c.X--) cout << c.Y << " ";
    }
    return 0;
}
