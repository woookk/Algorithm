//
//  6550 - 부분 문자열.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/10.
//

#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string a, b;

int main() {
    FASTIO
    
    while (cin >> a >> b) {
        int idx = 0;
        bool isSubStr = false;
        for (int i = 0; i < b.length(); i++) {
            if (a[idx] == b[i]) {
                idx++;
            }
            if (idx == a.length()) {
                isSubStr = true;
                break;
            }
        }
        
        if (isSubStr) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
