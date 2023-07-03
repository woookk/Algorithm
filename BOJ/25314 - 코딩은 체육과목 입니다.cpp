//
//  25314 - 코딩은 체육과목 입니다.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/03.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string ans;

int main() {
    FASTIO
    cin >> N;
    
    ans = "";
    for (int i = 1; i < N / 4; i++) {
        ans += "long ";
    }
    ans += "long int";
    cout << ans;
    return 0;
}
