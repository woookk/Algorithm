//
//  9095 - 1, 2, 3 더하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/13.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T, n;
int D[15];

int main(){
    FASTIO;
    
    D[1] = 1; D[2] = 2; D[3] = 4;
    for(int i = 4; i <= 10; i++){
        D[i] = D[i - 1] + D[i - 2] + D[i - 3];
    }
    
    cin >> T;
    while(T--){
        cin >> n;
        cout << D[n] << "\n";
    }
    return 0;
}
