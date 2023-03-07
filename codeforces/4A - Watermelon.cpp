//
// Created by 민병욱 on 2023/03/02.
//
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
    FASTIO
    int w;
    cin >> w;
    if (w > 2 && w % 2 == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}