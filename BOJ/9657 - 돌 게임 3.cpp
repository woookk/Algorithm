//
//  9657 - 돌 게임 3.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/23.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[1001];

int main(){
    FASTIO
    cin >> N;
    d[1] = 0;
    d[2] = 1;
    d[3] = 0;
    d[4] = 0;
    for(int i = 5; i <= N; i++){
        if(d[i - 1] || d[i - 3] || d[i - 4]){
            d[i] = 0;
        }
        else {
            d[i] = 1;
        }
    }
    if(d[N] == 0){
        cout << "SK";
    }
    else
        cout << "CY";
    return 0;
}
