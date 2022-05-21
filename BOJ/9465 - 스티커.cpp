//
//  9465 - 스티커.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/21.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
int a[2][100001], d[2][100001];

int main(){
    FASTIO;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        d[0][1] = a[0][1];
        d[1][1] = a[1][1];
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < 2; j++){
                d[j][i] = max(d[1 - j][i - 1], d[1 - j][i - 2]) + a[j][i];
            }
        }
        cout << max(d[0][n], d[1][n]) << "\n";
    }
    return 0;
}
