//
//  15684 - 사다리 조작.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/29.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M, H;
int ladder[32][13];
int ans = 4;

bool check(){
    for(int i = 1; i <= N; i++){
        int num = i;
        int cur = 1;
        while(cur <= H){
            if(!ladder[cur][num]) cur++;
            else {
                num = ladder[cur][num];
                cur++;
            }
        }
        if(i != num) return false;
    }
    return true;
}
void calc(int st, int k, int maxk){
    if(k == maxk){
        if(check()){
            ans = min(k, ans);
            return;
        }
        return;
    }
    for(int i = st; i <= H; i++){
        for(int j = 1; j < N; j++){
            if(ladder[i][j] || ladder[i][j + 1]) continue;
            ladder[i][j] = j + 1;
            ladder[i][j + 1] = j;
            calc(i, k + 1, maxk);
            ladder[i][j] = 0;
            ladder[i][j + 1] = 0;
        }
    }
}

int main(){
    FASTIO;
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ladder[a][b] = b + 1;
        ladder[a][b + 1] = b;
    }
    for(int i = 0; i < 4; i++){
        calc(1, 0, i);
        if(ans != 4) break;
    }
    if(ans == 4) ans = -1;
    cout << ans;
    return 0;
}
