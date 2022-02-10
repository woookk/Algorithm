//
//  10817 - 세 수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    FASTIO;
    vector<int> v;
    for(int i = 0; i < 3; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cout << v[1];
}
