//
//  2556 - 별 찍기 - 14.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/20.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << '*';
        }
        cout << "\n";
    }
    return 0;
}
