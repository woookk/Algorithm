//
//  17281 - ⚾.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/31.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int player[51][9];
int N, ans;
int order[9];
bool isused[9];


void calc(){
    int score = 0;
    int idx = 0;
    for(int inning = 0; inning < N; inning++){
        bool base[4] = {};
        int out = 0;
        while(out < 3){
            base[0] = true;
            int move = player[inning][order[idx++]];
            if (idx == 9) idx = 0;
            if (move == 0){
                out++;
                continue;
            }
            for(int i = 3; i >= 0; i--){
                if (!base[i]) continue;
                if (i + move >= 4) score++;
                else base[i + move] = true;
                base[i] = false;
            }
        }
    }
    ans = max(ans, score);
}

void brute(int k){
    if (k == 9){
        calc();
        return;
    }
    if (k == 3) {
        brute(k + 1);
        return;
    }
    for(int i = 1; i < 9; i++){
        if(!isused[i]){
            order[k] = i;
            isused[i] = true;
            brute(k + 1);
            isused[i] = false;
        }
    }
}
int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 9; j++){
            cin >> player[i][j];
        }
    }
    brute(0);
    cout << ans;
    return 0;
}
