//
//  2193 - 이친수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/17.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
long long d[91];

int main(){
    FASTIO;
    cin >> N;
    d[1] = 1;
    d[2] = 1;
    for(int i = 3; i <= N; i++){
        d[i] = d[i - 1] + d[i - 2];
    }
    cout << d[N];
    return 0;
}
