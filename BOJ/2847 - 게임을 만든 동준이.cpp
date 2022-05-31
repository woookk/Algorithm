//
//  2847 - 게임을 만든 동준이.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/31.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;
int score[101];

int main(){
    FASTIO
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> score[i];
    }
    int MX = score[N];
    for(int i = N - 1; i > 0; i--){
        if(score[i] >= MX){
            ans += score[i] - MX + 1;
            score[i] = MX - 1;
        }
        MX = score[i];
    }
    cout << ans;
    return 0;
}
