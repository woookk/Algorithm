//
//  2167 - 2차원 배열의 합.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/21.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int arr[305][305];

void solve() {
    int K;
    cin >> K;
    while (K--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 - 1][c1 - 1] << "\n";
    }
}

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
}

int main() {
    FASTIO
    input();
    solve();
    return 0;
}
