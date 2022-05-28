//
//  1541 - 잃어버린 괄호.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/28.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string s;

int ans, tmp;
int sign = 1;

int main(){
    FASTIO
    cin >> s;
    for(char c: s){
        if (c == '+' || c == '-'){
            ans += tmp * sign;
            if (c == '-') sign = -1;
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
    return 0;
}
