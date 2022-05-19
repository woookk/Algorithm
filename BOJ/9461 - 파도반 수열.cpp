//
//  9461 - 파도반 수열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/19.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
long long d[101];

int main(){
    FASTIO;
    
    d[1] = 1; d[2] = 1; d[3] = 1;
    d[4] = 2; d[5] = 2;
    
    for(int i = 6; i <= 100; i++){
        d[i] = d[i - 1] + d[i - 5];
    }
    
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        cout << d[N] << "\n";
    }
    return 0;
}
