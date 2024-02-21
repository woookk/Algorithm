//
//  12919 - A와 B 2.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/21.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string S, T;

bool ans;

void solve(string& cur) {
    if (ans) return;
    
    if (cur.compare(S) == 0) {
        ans = true;
        return;
    }
    
    if (cur.length() <= S.length()) return;
    
    string next = cur;
    if (next.back() == 'A') {
        next.pop_back();
        solve(next);
    }
    next = cur;
    if (next[0] == 'B') {
        reverse(next.begin(), next.end());
        next.pop_back();
        solve(next);
    }
    return; 
}

int main() {
    FASTIO
    cin >> S >> T;
    solve(T);
    cout << ans;
    return 0;
}

/*
 간단한 게임을 만들기로 했다. 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다. 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.
 - 문자열의 뒤에 A를 추가한다.
 - 문자열의 뒤에 B를 추가하고 문자열을 뒤집는다.
 
 **문자열 S에 'A'와 'B'를 하나씩 추가하여 T를 만들어내는 경우 완전탐색으로 진행할 경우 시간복잡도가 최대 2^50이 되어 시간초과 발생**
 
 문자열 T에 대해서 S로 만드는 방식으로 진행해야 한다. (T에서 S로 가는 경우에는 각 연산을 적용할 수 없는 경우가 많이 생기기 때문)
 문자열을 바꾸는 연산은
 - 문자열의 뒤에 A를 뺀다.
 - 문자열을 뒤집고 B를 뺀다로 바뀌게 된다.
 
 */
