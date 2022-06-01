//
//  2477 - 참외밭.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/31.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int K, ans;
pair<int, int> l[6];
int cnt[5], idx[2];

int main(){
    FASTIO
    cin >> K;
    for(int i = 0; i < 6; i++){
        cin >> l[i].X >> l[i].Y;
        cnt[l[i].X]++;
    }
    int tmp = 0;
    for(int i = 0; i < 6; i++){
        if (cnt[l[i].X] == 1) {
            idx[tmp++] = i;
        }
    }
    ans = l[idx[0]].Y * l[idx[1]].Y - l[(idx[0] + 3) % 6].Y * l[(idx[1] + 3) % 6].Y;
    cout << ans * K;
    return 0;
}
