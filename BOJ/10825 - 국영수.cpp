//
//  10825 - 국영수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/12.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
vector<tuple<int, int, int, string>> s;


int main(){
    FASTIO;
    cin >> N;
    string name;
    int kor, eng, math;
    for(int i = 0; i < N; i++){
        cin >> name >> kor >> eng >> math;
        s.push_back({-kor, eng, -math, name});
    }
    sort(s.begin(), s.end());
    for(auto& v : s){
        cout << get<3>(v) << "\n";
    }
    return 0;
}
