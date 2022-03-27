//
//  14889 - 스타트와 링크.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, MN = 1001;
int board[21][21];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    vector<int> team(N);
    fill(team.begin() + N / 2, team.end(), 1);
    do {
        int diff = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(team[i] != team[j]) continue;
                if(team[i] == 0) diff += (board[i][j] + board[j][i]);
                else diff -= (board[i][j] + board[j][i]);
            }
        }
        MN = min(MN, abs(diff));
    }
    while(next_permutation(team.begin(), team.end()));
    cout << MN;
    return 0;
}
