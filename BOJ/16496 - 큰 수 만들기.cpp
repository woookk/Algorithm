//
//  16496 - 큰 수 만들기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/04/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string ans;

bool cmp(const string& a, const string& b) {
    if (a.length() == b.length()) return a > b;
    string ab = a + b;
    string ba = b + a;
    if (ab > ba) return true;
    return false;
}

int main() {
    FASTIO
    cin >> N;
    vector<string> str(N);
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }
    
    sort(str.begin(), str.end(), cmp);
    
    bool isZero = true;
    for (auto s: str) {
        if (s.compare("0") != 0) isZero = false;
        ans += s;
    }
    if (isZero) ans = "0";
    cout << ans;
    return 0;
}

/*
 음이 아닌 정수가 N개 들어있는 리스트가 주어졌을 때, 리스트에 포함된 수를 나열하여 만들 수 있는 가장 큰 수를 구하는 프로그램을 작성
 
 사전형으로 비교가 되지 않기 때문에 직접 비교 함수를 작성해서 정렬하는 방식으로 풀이 진행
 1. 앞자리의 숫자가 큰 숫자들이 앞으로 (길이가 같다면 사전식으로 정렬)
 2. 앞자리의 숫자가 같다면, 두 수를 이어 붙인 뒤, 정렬을 진행하면 된다.
 
 ** 모든 숫자가 0으로만 구성되어 답이 00000과 같이 나오는 경우를 고려하지 못해서 오답 처리**
 */
