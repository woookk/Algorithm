//
//  1254 - 팰린드롬 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/31.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string str;

bool isPalindrome(string s) {
    int len = s.length();
    
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    FASTIO
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (isPalindrome(str.substr(i))) {
            cout << str.length() + i;
            return 0;
        }
    }
    return 0;
}
