//
//  1051 - 숫자 정사각형.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/12/30.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
char board[51][51];
int ans = 1;

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int len = min(N - i, M - j);
            for (int k = 1; k < len; k++) {
                if (board[i][j] == board[i + k][j] && board[i][j] == board[i][j + k] && board[i][j] == board[i + k][j + k]) ans = max(ans, (k + 1) * (k + 1));
            }
        }
    }
    
    cout << ans;
    return 0;
}
