//
//  11656 - 접미사 배열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string s;
vector<string> v;

int main(){
    FASTIO;
    cin >> s;
    int len = (int)s.length();
    
    for(int i = 0; i < len; i++){
        string tmp = s.substr(i);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(auto& c : v){
        cout << c << "\n";
    }
    return 0;
}
