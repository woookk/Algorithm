//
//  2579 - 계단 오르기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int s[301];
int D[301][3];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> s[i];
    if(N == 1){
        cout << s[1];
        return 0;
    }
    D[1][1] = s[1];
    D[1][2] = 0;
    D[2][1] = s[2];
    D[2][2] = s[1] + s[2];
    for(int i = 3; i <= N; i++){
        D[i][1] = max(D[i - 2][1], D[i - 2][2]) + s[i];
        D[i][2] = D[i - 1][1] + s[i];
    }
    cout << max(D[N][1], D[N][2]);
    return 0;
}
