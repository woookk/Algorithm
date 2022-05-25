//
//  1439 - 뒤집기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/25.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string s;

int main(){
    FASTIO;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != s[i + 1]) cnt++;
    }
    cout << cnt / 2;
    return 0;
}
