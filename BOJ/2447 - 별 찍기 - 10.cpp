//
//  2447 - 별 찍기 - 10.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/04.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

char board[2200][2200];

void print(int x, int y, int n){
    if(n == 3){
        for(int i = x; i < x + n; i++)
            for(int j = y; j < y + n; j++){
                if(i == x + 1 && j == y + 1) continue;
                board[i][j] = '*';
            }
        return;
    }
    int N = n / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1) continue;
            print(x + i * N, y + j * N, N);
        }
    }
}
int main(){
    FASTIO;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        fill(board[i], board[i] + N, ' ');
    print(0, 0, N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}
