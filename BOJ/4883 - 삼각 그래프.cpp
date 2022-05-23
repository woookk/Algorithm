//
//  4883 - 삼각 그래프.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/23.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
int a[100001][3], d[100001][3];

int main(){
    FASTIO;
    int idx = 0;
    while(1){
        idx++;
        int N;
        cin >> N;
        if(N == 0) break;
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < 3; j++){
                cin >> a[i][j];
            }
        }
        d[1][0] = 1001;
        d[1][1] = a[1][1];
        d[1][2] = a[1][1] + a[1][2];
        for(int i = 2; i <= N; i++){
            d[i][0] = a[i][0] + min(d[i - 1][0], d[i - 1][1]);
            d[i][1] = a[i][1] + min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]});
            d[i][2] = a[i][2] + min({d[i - 1][1], d[i - 1][2], d[i][1]});
        }
        cout << idx << ". " << d[N][1] << "\n";
    }
}
