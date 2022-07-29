//
//  11478 - 서로 다른 부분 문자열의 개수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/29.
//

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string s;

int main(){
    FASTIO
    cin >> s;
    unordered_set<string> us;
    for(int st = 0; st < s.length(); st++){
        for(int len = 1; st + len <= s.length(); len++){
            us.insert(s.substr(st, len));
        }
    }
    cout << us.size();
    return 0;
}
