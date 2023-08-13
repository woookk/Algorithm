//
//  28701 - 세제곱의 합.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/13.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int sum, ans;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    cout << sum << "\n";
    cout << sum * sum << "\n";
    for (int i = 1; i <= N; i++) {
        ans += i * i * i;
    }
    cout << ans;
    return 0;
}
