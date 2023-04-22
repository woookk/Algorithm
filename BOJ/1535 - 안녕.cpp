//
//  1535 - 안녕.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/22.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int L[25], J[25];
int d[105];

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> J[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 100; j >= L[i]; j--) {
            d[j] = max(d[j], d[j - L[i]] + J[i]);
        }
    }
    cout << d[99];
    
    return 0;
}
