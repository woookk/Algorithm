//
//  9625 - BABBA.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/10.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int K;

int main() {
    FASTIO
    cin >> K;
    vector<int> dpA(K + 1, 0), dpB(K + 1, 0);
    dpA[1] = 0;
    dpB[1] = 1;
    for (int i = 2; i <= K; i++) {
        dpA[i] = dpB[i - 1];
        dpB[i] = dpA[i - 1] + dpB[i - 1];
    }
    cout << dpA[K] << " " << dpB[K] << "\n";
    return 0;
}
