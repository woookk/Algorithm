//
//  9372 - 상근이의 여행.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/28.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
int N, M, a, b;


int main() {
    FASTIO
    cin >> T;
    while (T--) {
        cin >> N >> M;
        while (M--) {
            cin >> a >> b;
        }
        cout << N - 1 << "\n";
    }
    return 0;
}
