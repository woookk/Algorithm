//
//  1463 - 1로 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/13.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int D[1000001];
int N;

int main(){
    FASTIO;
    cin >> N;
    D[1] = 0;
    for(int i = 2; i <= N; i++){
        D[i] = D[i - 1] + 1;
        if(i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
        if(i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
    }
    cout << D[N];
    return 0;
}
