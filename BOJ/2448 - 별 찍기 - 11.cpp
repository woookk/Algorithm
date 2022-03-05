//
//  2448 - 별 찍기 - 11.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/05.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

char board[3100][6200];

void print(int x, int y, int n){
    if(n == 3){
        board[x][y + 2] = '*';
        board[x + 1][y + 1] = '*'; board[x + 1][y + 3] = '*';
        for(int i = 0; i < 2 * n - 1; i++){
            board[x + 2][y + i] = '*';
        }
        return;
    }
    int N = n / 2;
    print(x, y + N, N);
    print(x + N, y, N);
    print(x + N, y + n, N);
}
int main(){
    FASTIO;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        fill(board[i], board[i] + 2 * N - 1, ' ');
    }
    print(0, 0, N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2 * N - 1; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}
