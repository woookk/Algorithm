//
//  2457 - 공주님의 정원.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
int N, ans;
vector<pair<int, int>> flower;

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm * 100 + sd, em * 100 + ed});
    }
    
    int cur = 301;
    while(cur < 1201){
        int nxCur = cur;
        for(int i = 0; i < N; i++){
            if(flower[i].X <= cur && flower[i].Y > nxCur)
                nxCur = flower[i].Y;
        }
        if(nxCur == cur){
            cout << 0;
            return 0;
        }
        ans++;
        cur = nxCur;
    }
    cout << ans;
    return 0;
}
