//
//  9084 - 동전.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/25.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
int c[21];
int d[10001];

int main(){
    FASTIO;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> c[i];
        }
        cin >> M;
        fill(d, d + 10001, 0);
        d[0] = 1;
        for(int i = 1; i <= N; i++){
            for(int j = c[i]; j <= M; j++){
                d[j] += d[j - c[i]];
            }
        }
        cout << d[M] << "\n";
    }
    return 0;
}
