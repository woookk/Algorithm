//
//  5648 - 역원소 정렬.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
vector<long long> v;

int main(){
    FASTIO;
    cin >> N;
    string tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        reverse(tmp.begin(), tmp.end());
        v.push_back(stoll(tmp));
    }
    sort(v.begin(), v.end());
    for(auto c : v) {
        cout << c << "\n";
    }
    return 0;
}
