//
//  7579 - 앱.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/21.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int C;
int A[105];
int D[10005];

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> C;
        
        for (int j = 10000; j >= C; j--) {
            D[j] = max(D[j], D[j - C] + A[i]);
        }
    }
    
    for (int i = 0; i <= 10000; i++) {
        if (D[i] >= M) {
            cout << i;
            break;
        }
    }
    return 0;
}
