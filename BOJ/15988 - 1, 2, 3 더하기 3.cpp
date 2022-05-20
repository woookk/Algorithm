//
//  15988 - 1, 2, 3 더하기 3.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/20.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
int d[1000001];

int main(){
    FASTIO;
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i <= 1000000; i++){
        for(int j = 1; j <= 3; j++){
            d[i] = (d[i] + d[i - j]) % 1000000009;
        }
    }
    
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << d[n] << "\n";
    }
    return 0;
}
