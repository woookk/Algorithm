//
//  2133 - 타일 채우기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/31.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[31];

int main(){
    FASTIO
    cin >> N;
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    d[3] = 0;
    for(int i = 3; i <= N; i++){
        d[i] += (d[i - 2] * 3);
        for(int j = i - 4; j >= 0; j -= 2)
            d[i] += (d[j] * 2);
    }
    cout << d[N];
    return 0;
}
