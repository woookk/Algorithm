//
//  11659 - 구간 합 구하기 4.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/14.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int a[100001], d[100001];

int main(){
    FASTIO;
    cin >> N >> M;
    d[0] = 0;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        d[i] =  d[i - 1] + a[i];
    }
    while(M--){
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i - 1] << "\n";
    }
    return 0;
}
